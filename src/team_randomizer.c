#include "global.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "constants/species.h"
#include "team_randomizer.h"

void RandomizePartyPokemon(struct Pokemon *party)
{
    struct Pokemon *mon;
    u16 i, rnd, oldSpecies, zero = 0, personality;
    u8 eventLegal = 1;
    for(i = 0; i < PARTY_SIZE; ++i) {
        mon = &party[i];

        // do not randomize empty slots or eggs
        if(!(oldSpecies = GetMonData(mon, MON_DATA_SPECIES, 0)) || GetMonData(mon, MON_DATA_IS_EGG, 0)) {
            continue;
        }

        // first clear existing moves. This is so we can give them a new set after
        for(rnd = 0; rnd < 4; rnd++) {
            SetMonData(mon, MON_DATA_MOVE1 + rnd, &zero);
        }

        // find a new species; the UNOWN_B - Z line is bugged, so skip over them
        // TODO: Is there an easy way to find different formes? eg, Unown
        do {
            rnd = 1 + Random() % SPECIES_DEOXYS;
        } while(rnd >= SPECIES_OLD_UNOWN_B && rnd <= SPECIES_OLD_UNOWN_Z);
        
        // TODO: Do we want to fix EXP here? That might get weird

        // Force the new species
        SetMonData(mon, MON_DATA_SPECIES, &rnd);

        // Ensure their stats are up to date
        CalculateMonStats(mon);

        // give new moves
        GiveMonInitialMoveset(mon);

        // make sure it's named correctly (nick names are preserved, species names are not)
        EvolutionRenameMon(mon, oldSpecies, rnd);

        // Mew and Deoxys will disobey unless this bit is set
        SetMonData(mon, MON_DATA_EVENT_LEGAL, &eventLegal);

        // add it to the pokedex (probably unnecessary, but cool)
        personality = GetMonData(mon, MON_DATA_PERSONALITY, 0);
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(rnd), FLAG_SET_SEEN, personality);
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(rnd), FLAG_SET_CAUGHT, personality);
    }
}

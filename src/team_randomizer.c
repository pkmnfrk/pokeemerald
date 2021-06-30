#include "global.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "constants/species.h"
#include "team_randomizer.h"

void RandomizePartyPokemon(struct Pokemon *party)
{
    struct Pokemon *mon;
    u16 i, rnd, oldSpecies, tmp = 0, personality;
    for(i = 0; i < PARTY_SIZE; ++i) {
        mon = &party[i];
        if(!(oldSpecies = GetMonData(mon, MON_DATA_SPECIES, 0)) || GetMonData(mon, MON_DATA_IS_EGG, 0)) {
            continue;
        }
        // first clear existing moves
        for(rnd = 0; rnd < 4; rnd++) {
            SetMonData(mon, MON_DATA_MOVE1 + rnd, &tmp);
        }
        // set new species
        // the UNKNOWN_B - Z line is bugged, so skip over them
        do {
            rnd = 1 + Random() % SPECIES_DEOXYS;
        } while(rnd >= SPECIES_OLD_UNOWN_B && rnd <= SPECIES_OLD_UNOWN_Z);
        
        SetMonData(mon, MON_DATA_SPECIES, &rnd);
        CalculateMonStats(mon);
        // give new moves
        GiveMonInitialMoveset(mon);
        // make sure it's named correctly
        EvolutionRenameMon(mon, oldSpecies, rnd);
        personality = GetMonData(mon, MON_DATA_PERSONALITY, 0);
        // add it to the pokedex
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(rnd), FLAG_SET_SEEN, personality);
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(rnd), FLAG_SET_CAUGHT, personality);
    }
}

# Pokémon Emerald - Team Randomizer Edition

This is a decompilation of Pokémon Emerald. It has been enhanced with a randomizer function that
will change the species of your Pokémon after every battle. That Torchic might turn into a
Pikachu, which might turn into Rayquaza, which might turn into Metapod. Fun!

## Features:
* Re-roll Pokémon species after each battle. This happens at the _end_ of each battle, regardless
  of outcome (win or lose). It also happens in places like the Battle Tower where you normally
  can not earn EXP.
* Moves will be re-assigned based on the new species and level (as though it was a wild Pokémon).
  This does render TMs less useful, since any moves learned will be erased after the next battle.
  * However, to be nice*, PP will be restored at the same time.
* EXP, EVs, IVs, Personality values, etc will all stay the same during randomization. This means
  that Pokémon may change genders, levels, etc if the relevant formulae are different between
  old and new species.
* Pokémon names will change with the same rules as evolution (eg, nicknames will be preserved)
* Mew and Deoxys, which would normally be disobedient due to not being Event Pokémon, will
  function as normal.

[*] - OK, technically this has nothing to do with being nice, and more to do with the mechanism
that assigns the moves. However, the alternative would be pretty unworkable, so don't worry too
much about it.

## Other notes:
* HMs are not excluded from the move set resetting, so if you need an HM you will likely
  need to teach it immediately before using it. If you don't have anyone who can learn it, then
  just get into another battle!
  * It _may_ be possible to softlock if you need an HM in an area where you cannot engage in
    Pokémon battles and your team is not capable of learning it. However, this might not be a
    real concern in practice. Getting at least the Old Rod is recommended to mitigate this risk.
* Because movesets are based on the Pokémon's level list, at early levels less-evolved Pokémon
  might be better than more-evolved Pokémon. You would be surprised how many stage-1 Pokémon have
  moves on their level list that their evolved forms don't.
* You should save often. This is a crazy hack and things might go wrong! At the time of writing,
  I have not completed a full playthrough of the game. Through Slateport, however, things seem
  fine.
* This hack is _not_ compatible with the Universal Pokémon Randomizer (ZX or otherwise). I have
  little interest in adding support, but if you want to do it, feel free.
  * For clarity, it's not that I don't want this, it's that it would be a lot of work, and I have
    a day job :)

## Known Issues
* There was, at one point, a glitch that caused the game to lock up while rewarding EXP. This
  was somewhat related to the Pomeg Berry glitch, which has been patched, so hopefully this
  particular bug is gone.
* Pokémon levels are not fixed, but are dependant on the EXP curve used by a species and how
  much EXP they currently have. I may or may not attempt to fix this.

If you see anything 

## Setup

To set up the repository, see [INSTALL.md](INSTALL.md).


## See also

This project would not be possible without the hard work put into the [original decompilation
project](https://github.com/pret/pokeemerald). Thank you pret and everyone else!

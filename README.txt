======== INSTALLATION ========

This mod requires the ndmodloader (https://www.nexusmods.com/thelastofuspart2/mods/32).

Simply put the infinite_sprint.psarc file in your mods folder.

If you have other mods installed that edit the "player_settings.bin" file and you're experiencing issues, please let me know.

The optional below section requires ndarc (https://www.nexusmods.com/thelastofuspart2/mods/31).

======== CUSTOM STAMINA ========

This section is optional if you wish to define a custom stamina amount. By default, this mod
provides infinite stamina. If that's all you want, you don't need to change anything.

Alternatively, the file "multiplier.txt" defines a value that is multilpied with the game's default stamina __drain__ amount.
If you want to have *more* stamina than default, set the multiplier to a value less than
1.0, such that you'll have less stamina drain. If you want to have less stamina, set this value to a value
greater than 1.0. If you set the multiplier to 0.0, you'll have infinite stamina.

After chaning the value inside the "multiplier.txt" file, ensure that you have "ndarc.exe" in the same directory
as this file. You can then run the "patch_stamina.exe" program. This will create a new ".psarc" file 
with the custom stamina drain amount in the name. Copy this file into your mods folder. Make sure to remove
any other files associated with this mod, as they will otherwise conflict. 

======== CHANGELOG ========

* 2.0.0 | Added custom stamina amount
* 1.0.0 | Release
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    const short offset = 0x6508;
    float multiplier, new_stamina_value;
    FILE *bin_file, *multiplier_file;

    bin_file = fopen("infinite_sprint_unpacked/bin/dc1/player-settings.bin", "r+b");
    if (bin_file == NULL)
    {
        printf("Couldn't open file \"infinite_sprint_unpacked\\bin\\dc1\\player_settings.bin\".");
        getchar();
        return 1;
    }

    multiplier_file = fopen("multiplier.txt", "r");
    if (multiplier_file == NULL)
    {
        printf("Couldn't open file multiplier.txt.");
        getchar();
        return 1;
    }
    struct stat buffer;
    if (stat(".\\ndarc.exe", &buffer) != 0)
    {
        printf("ndarc.exe wasn't found in this folder.\n");
        getchar();
        return 1;
    }

    fscanf(multiplier_file, "%f", &multiplier);

    new_stamina_value = 20.f * multiplier;
    fseek(bin_file, offset, SEEK_SET);
    fwrite(&new_stamina_value, sizeof(float), 1, bin_file);
    fclose(bin_file);
    fclose(multiplier_file);
    printf("Changed stamina drain value from %f to %f\n", 20.f, new_stamina_value);
    char command[100];
    sprintf_s(command, 100, ".\\ndarc.exe -c .\\infinite_sprint_unpacked -o .\\%.2fx_stamina.psarc > NUL", new_stamina_value);
    printf("Creating the new archive .\\%.2fx_stamina.psarc...\n", new_stamina_value);
    system(command);

    printf("New archive created successfully. You can now copy it into your mods folder. Press any button to quit.\n");
    getchar();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "struct_file.h"



int load_from_file(struct Chest *chest, char *file_name);


int main(int arc, char **argv)
{
    printf("Enter name of file to load Chest struct from.\n");
    char file_name[256];
    scanf("%s", file_name);
    printf("Loading %s\n", file_name);
    struct Chest *chest = malloc(sizeof(struct Chest));
    printf("Allocated %d bytes to chest. Sizeof chest: %d\n",
        (int)sizeof(struct Chest), (int)sizeof(*chest));

    if (load_from_file(chest, file_name) == 1)
    {
        printf("load_from_filed returned failuer code, exiting\n");
        return 1;
    }
    return 0;
}



int load_from_file(struct Chest *chest, char *file_name)
{

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        return 1;
    }
    strcat(cwd, "/");
    strcat(cwd, file_name);
    printf("Opening file with path %s\n", cwd);
    FILE *fp;

    fp = fopen(cwd, "rb");
    if (!fp)
    {
        printf("failure to open file, exiting\n");
        return 1;
    }
    
    if (fread(chest, sizeof(struct Chest), 1, fp) == 0)
    {
        printf("fread read 0 objects, exiting\n");
        return fclose(fp);
    }    
    printf("Read name: %s, gp: %d\n", chest->name, chest->gp);
    return fclose(fp);

}

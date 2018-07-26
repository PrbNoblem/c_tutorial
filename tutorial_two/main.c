#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "struct_file.h"

/*
* Test for structs and pointers
*/


int save_to_file(struct Chest *save_this, char *filepath);


int main(int argc, char **argv)
{

    struct Chest *pchest  = malloc(sizeof(struct Chest));

    char input_name[256];
    int input_gp;
    printf("Enter name of chest.\n");
    scanf("%s", input_name);
    printf("Name: %s\nEnter number of gp.\n", input_name);
    scanf("%d", &input_gp);
    printf("Number gp: %d\n", input_gp);

    pchest->gp = input_gp;
    strcpy(pchest->name, input_name);

    printf("name: %s, gp: %d\n", pchest->name, pchest->gp);

    printf("random info:\nSize of struct: %d\nSize of name: %d\nSize of gp: %d\n",
        (int)sizeof(*pchest), (int)sizeof(input_name), (int)sizeof(input_gp));
    printf("Size of pchest->gp: %d\nSize of pchest->name: %d\n",
        (int)sizeof(pchest->gp), (int)sizeof(pchest->name));    

    if (save_to_file(pchest, "testfile.txt") != 0)
    {
        printf("save to file returned 1\n");
        return 1;
    }

    
    return 0;
}


int save_to_file(struct Chest *save_this, char *filepath)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        return 1;
    }
    strcat(cwd, "/");
    strcat(cwd, filepath);
    printf("Saving to file %s\n", cwd);
    FILE *fp;
    fp = fopen(cwd, "wb");
    if (!fp)
    {
        printf("could open file\n");
        return 1;
    }
    if (fwrite(save_this, sizeof(*save_this), 1, fp) != 1)
    {
        printf("could not write to file\n");
        return 1;
    }
    //fprintf(fp, "%s\n%d\n", save_this->name, save_this->gp);
    fclose(fp);
    return 0;
}



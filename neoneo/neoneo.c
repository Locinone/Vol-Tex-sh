#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>


int neoneo(){
    char ch, file_name[25];
    FILE *fp;

    char *cmd1 = "whoami >> $HOME/tmp.voltex;hostname >> $HOME/tmp.voltex";
    char *args1[] = {cmd1,NULL};
    execv(cmd1,args1);

    fp = fopen("$HOME/tmp.voltex","r"); //do not work idw

    if (fp == NULL){
        errx(-1,"filename not valid");
    }
    while((ch = fgetc(fp)) != EOF)
        printf("%c",ch);
    
    fclose(fp);
    char *cmd2 = "rm $HOME/tmp.voltex";
    execv(cmd2,NULL);    

    printf("\n");
    printf("done\n");

    return 0;
}


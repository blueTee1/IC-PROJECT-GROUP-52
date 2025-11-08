#include<stdio.h>
int main(){
    FILE *fin,*fout;
    fin = fopen("img.jpg","rb");
    fout = fopen("encrypted.bin","wb");
    if(!fin){
        perror("Error opening input file");
        return 1;
    }

    if (!fout){
       perror("Error opening output file");
       fclose(fin);
       return 1;
    }
    int ch;
    char key ='k';
    char enc;
    while((ch = fgetc(fin)) != EOF){
        enc = ch^key;
        fwrite(&enc,1,1,fout);
    }
    fclose(fin);
    fclose(fout);
    printf("Encrypted to encrypted.bin");
    return 0;

}

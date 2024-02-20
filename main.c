#include<stdio.h>
#include<stdlib.h>
#include "deco.h"
#include "dictionnaire_functions.h"

int main(){
  struct BTnode *rootNode = getdic("");
  FILE *f=fopen("dico.txt","r");
  if(!f)exit(1);
  char ch[50];
  int a;
  while(1){
    a=fscanf(f,"%s",ch);
    if(a==-1)break;
    rootNode = dicoInsererMot(rootNode,ch);
  }
  int s;
  while(s!=7){
    printf("\n1.nombre d'occurence\n2.Insert\n3.suppression d'un mot\n4.suppression de tous les mots dans le dictionnaire\n5.nombre de mots totale\n6.nombre de mots differents\n7.Exit\nYour choice please..");
    scanf("%d",&s);
    switch (s) {
      case 1:
        printf("\nInsert word:\n");
        scanf("%s",ch);
        printf("le nembre d'occurence de %s est %d\n",ch,dicoNbOcc(rootNode,ch));
        break;
      case 2:
        printf("\nInsert word:\n");
        scanf("%s",ch);
        rootNode = dicoInsererMot(rootNode,ch);
        break;
      case 3:
        printf("\nInsert word:\n");
        scanf("%s",ch);
        dicosuppMot(rootNode,ch);
        break;
      case 4:
        rootNode = getdic("");
        break;
      case 5:
        printf("\nLe nombre totale de mots est %d\n",nombre_mot);
        break;
      case 6:
        printf("\nLe nombre de mots differents est %d\n",nombre_mot_diff);
        break;
      case 7:
        break;
    }
  }
  fclose(f);
return 0;
}

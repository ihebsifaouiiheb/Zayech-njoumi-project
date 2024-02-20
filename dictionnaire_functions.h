#ifndef DICTIONNAIRE_FUNCTIONS_H_INCLUDED
#define DICTIONNAIRE_FUNCTIONS_H_INCLUDED

int nombre_mot=0,nombre_mot_diff=0;

struct BTnode *getdic(char value[]){
  struct BTnode *rootNode = arbreConsVide(), *ytaba3;
  int i=0;
  nombre_mot=0;
  nombre_mot_diff=0;
  if(!value[i])return rootNode;
  char c=value[i];
  arbreRempli(rootNode,c,0,NULL,NULL);
  ytaba3=rootNode;
  ++i;
  while(c=value[i]){
    ytaba3=arbreCreeAgauche(ytaba3,c,0);
    ++i;
  }
  arbreCreeAgauche(ytaba3,'\0',1);
  nombre_mot=1;
  nombre_mot_diff=1;
  return rootNode;
}

struct BTnode *dicoInsererMot(struct BTnode *rootNode, char value[]){
  if(arbreEstVide(rootNode))
  return getdic(value);
  int i=0;
  char c;
  struct BTnode *ytaba3=rootNode;
  while(1){
    c=value[i++];
    while(ytaba3->keyVal != c){
      if(arbreFilsDroit(ytaba3) == NULL) break;
      ytaba3 = arbreFilsDroit(ytaba3);
    }
    if(ytaba3->keyVal == c){
      if(c=='\0'){
        if(ytaba3->occ==0)nombre_mot_diff++;
        ytaba3->occ++;
        break;
      }
      if(ytaba3->leftNode==NULL){printf("el return sar fel ligne eli fiha if(ytaba3->leftNode==NULL){printf");}
      ytaba3=arbreFilsGauche(ytaba3);
    }else{
      ytaba3=arbreCreeAdroit(ytaba3,c,0);
      nombre_mot_diff++;
      if(c=='\0'){
        ytaba3->occ=1;
        break;
      }
      while(c=value[i++])
        ytaba3=arbreCreeAgauche(ytaba3,c,0);

      ytaba3=arbreCreeAgauche(ytaba3,'\0',1);
      break;
    }
  }
  nombre_mot++;
  return rootNode;
}

struct BTnode *dicosuppMot(struct BTnode *rootNode, char value[]){
  if(arbreEstVide(rootNode))
  return NULL;
  int i=0;
  char c;
  struct BTnode *ytaba3=rootNode;
  while(1){
    c=value[i++];
    while(ytaba3->keyVal != c){
      if(arbreFilsDroit(ytaba3) == NULL) break;
      ytaba3 = arbreFilsDroit(ytaba3);
    }
    if(ytaba3->keyVal == c){
      if(c=='\0'){
        ytaba3->occ--;
        if(ytaba3->occ==0)nombre_mot_diff--;
        if(ytaba3->occ<0) ytaba3->occ=0;
        else nombre_mot--;
        break;
      }
      if(ytaba3->leftNode==NULL){printf("el return sar fel ligne eli fiha if(ytaba3->leftNode==NULL){printf");}
      ytaba3= arbreFilsGauche(ytaba3);
    }else break;
  }
  return rootNode;
}

int dicoNbOcc(struct BTnode *rootNode,char value[]){
  if(arbreEstVide(rootNode))
  return 0;
  int i=0;
  char c;
  struct BTnode *ytaba3=rootNode;
  while(1){
    c=value[i++];
    while(ytaba3->keyVal != c){
      if(arbreFilsDroit(ytaba3) == NULL) break;
      ytaba3 = arbreFilsDroit(ytaba3);
    }
    if(ytaba3->keyVal == c){
      if(c=='\0')break;
      if(ytaba3->leftNode==NULL){printf("el return sar fel ligne eli fiha if(ytaba3->leftNode==NULL){printf2");return;}
      ytaba3=arbreFilsGauche(ytaba3);
    }else return 0;
  }
  return ytaba3->occ;
}


#endif

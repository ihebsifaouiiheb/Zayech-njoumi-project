#ifndef DECO_H_INCLUDED
#define DECO_H_INCLUDED

struct BTnode{
char keyVal;
struct BTnode *leftNode;
struct BTnode *rightNode;
int occ;
};

struct BTnode *arbreConsVide(){
  return malloc(sizeof(struct BTnode));
}

int arbreEstVide(struct BTnode *node){
  if(node==NULL)return 1;//arbre vide
  else if(node->keyVal==0)return 1;//arbre vide
  return 0;//arbre n'est pas vide
}

struct BTnode *arbreCreeAgauche(struct BTnode *node, char c, int occurence){
  node->leftNode = malloc(sizeof(struct BTnode));
  arbreRempli(node->leftNode,c,occurence,NULL,NULL);
  return node->leftNode;
}

struct BTnode *arbreCreeAdroit(struct BTnode *node, char c, int occurence){
  node->rightNode = malloc(sizeof(struct BTnode));
  arbreRempli(node->rightNode,c,occurence,NULL,NULL);
  return node->rightNode;
}

struct BTnode *arbreFilsGauche(struct BTnode *node){
  return node->leftNode;
}

struct BTnode *arbreFilsDroit(struct BTnode *node){
  return node->rightNode;
}

void arbreRempli(struct BTnode *node,char c,int occurence,struct BTnode *left,struct BTnode *right){
  node->keyVal = c;
  node->occ=occurence;
  node->rightNode = right;
  node->leftNode = left;
}


#endif

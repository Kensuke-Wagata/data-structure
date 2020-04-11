#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef struct _node{
     int element;
     struct _node *right;
     struct _node *left;
 }node;
 
 typedef struct _tree{
     node *root;
 }tree;
 
 tree* create() {
     tree *T = (tree *)malloc(sizeof(tree));
     T->root = NULL;
     return T;
}

 void insert_body(node *now, node *add) {
     // 左に行く
     if (now->element > add->element) {
         if(now->left == NULL) { now->left = add; }
         else{ insert_body(now->left, add); }
     }
     // 右に行く
     else{
         if(now->right == NULL) { now->right = add; }
         else{ insert_body(now->right, add); }
     }
 return;
 }
 
 void insert(tree *T, int element) {
     node *add = (node *)malloc(sizeof(node));
     add->element = element;
     add->right = NULL;
     add->left = NULL;
    
     if(T->root == NULL) { T->root = add; }
     else{ insert_body(T->root, add); }
     return;
 }

void find_body( node *now, int data){
  if(now == NULL) printf("Not Found");
  else if(data < now->element)
    return find_body(now->left, data);
  else if(data > now->element)
    return find_body(now->right, data);
  else if(data == now->element){
    printf("Found");
  }else { 
    printf("Not Found");
  }
}

void find(tree *T, int data){
  find_body(T->root, data);
  printf("\n");
  return;
}
 


 int main() {
     tree *T = create();
     int i = 0;
     int data[5];
     int a[] = {2, 3, 5, 6, 7, 9, 10, 12, 15, 20, 21, 27, 28, 29, 39, 41, 42, 44, 46, 48, 50};
    
     for(i = 0; i < 21; i++)  insert(T, a[i]);

     for(i = 0; i < 5; i++)  scanf("%d", &data[i]);

     for(i = 0; i < 5; i++)  find(T, data[i]);	 
  
     return 0;
 }

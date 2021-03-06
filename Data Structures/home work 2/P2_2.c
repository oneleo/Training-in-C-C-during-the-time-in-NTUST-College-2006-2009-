#include<stdlib.h>
#include<stdio.h>
short min,max;
typedef struct node
{
   int data;
   struct node *right_child,*left_child;
}
node;
void insert(node **tree,node *item)   /*Insert binary tree.*/
{
  short ran_num=rand()%2;             /*Random number range 0 to 1, to control insert left or reght.*/
  if(!(*tree))                        /*Whither tree is a empty tree or not.*/
  {
    *tree = item;                     /*Create binary tree node.*/
    return;
  }
  if(ran_num==0)                      /*Go left.*/
  {
    insert(&(*tree)->left_child,item);
  }
  else if(ran_num==1)                 /*Go right.*/
  {
    insert(&(*tree)->right_child,item);
  }
}
void preorder(node *root)             /*Preorder traversal*/
{
  if(root!=NULL)
  {
    printf("%4d ",root->data);        /*Access and process its root.*/
    preorder(root->left_child);       /*Traverse its left subtree in preorder.*/
    preorder(root->right_child);      /*Traverse its right subtree in preorder.*/
  }
}
void inorder(node *root)              /*Ineorder traversal*/
{
  if(root!=NULL)
  {
    inorder(root->left_child);        /*Traverse its left subtree in preorder.*/
    printf("%4d ",root->data);        /*Access and process its root.*/
    inorder(root->right_child);       /*Traverse its right subtree in preorder.*/
   }
}
void postorder(node *root)            /*Postorder traversal*/
{
  if(root!=NULL)
  {
    postorder(root->left_child);      /*Traverse its left subtree in preorder.*/
    postorder(root->right_child);     /*Traverse its right subtree in preorder.*/
    printf("%4d ",root->data);        /*Access and process its root.*/
  }
}
int main(void)
{
  node *current,*root;                /*Create a root and current of binary tree.*/
  srand((unsigned)time(NULL));        /*Seed of rand.*/
  int i;                              /*Loop control i.*/
  root=NULL;                          /*Set root is null.*/
  printf("Original numbers:\n");
  for(i=1;i<=20;i++)                  /*Start to create binary tree which have twenty node.*/
  {
    current=(node*)malloc(sizeof(node));/*Set the new node to storing memery.*/
    current->left_child=NULL;         /*Set this new node link to null.*/
    current->right_child=NULL;
    current->data=rand()%1001;        /*Random number range 0 to 1000.*/
    printf("%4d ",current->data);
    insert(&root,current);            /*Insert binary tree.*/
  }
  printf("\nPreorder traversal:\n");
  preorder(root);                     /*Preorder traversal*/
  printf("\nInorder traversal:\n");
  inorder(root);                      /*Preorder inorder*/
  printf("\nPostorder traversal:\n");
  postorder(root);                    /*Preorder postorder*/
  getch();
  return 0;
}

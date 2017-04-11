#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *newnode(int item)
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
   temp->data=item;
   temp->left=NULL;
   temp->right=NULL;
}
void inorder(struct node *root)
{
  if(root!=NULL)
    {
       inorder(root->left);
       printf("%d\n",root->data);
       inorder(root->right);
    }
}
struct node *insert(struct node *node ,int data)
{
  if(node==NULL)
    return  newnode(data);
  if(data<node->data)
    node->left=insert(node->left,data);
   else if(data>node->data)
     node->right=insert(node->right,data);
   return node;
}
int height1(struct node *root)
{
 int leftheight;
  if(root==NULL)
   return 0;
  else
   {
     leftheight=height1(root->left);
       return(leftheight+1);
   }
}
int height2(struct node *root)
{
  int rightheight;
   if(root==NULL)
     return 0;
   else
    {
       rightheight=height2(root->right);
       return(rightheight+1);
    }
}
int depth(struct node *node)
{
  int rd,ld;
  if(node==NULL)
   return 0;
  ld=depth(node->left);
  rd=depth(node->right);
   if(ld>rd)
    return (ld+1);
   else
    return (rd+1);
}
int iscomplete(struct node *node)
{
  int rd,ld;
  if(node==NULL)
   return 1;
  ld=depth(node->left);
  rd=depth(node->right);
  return(ld==rd && iscomplete(node->left) && iscomplete(node->right));
}
int main()
{
   int i,m,n;
  struct node *root=NULL;
  root=insert(root,50);
   printf("how many values yu want");
   scanf("%d",&m);
   for(i=1;i<m;i++)
    { 
      printf("values in trees");
      scanf("%d",&n);
      insert(root,n);
     }
     printf("\nthe output is\n ");
    inorder(root);
    printf("the balancing factor of tree is %d\n",(height1(root)-height2(root)));
    iscomplete(root);
    {
    printf("the tree is complete");
    }
}     

#include <stdio.h>
#include <stdlib.h>
#define N 1000
typedef struct node{
	 int data;
	 struct node *lchild;
	 struct node *rchild;
}BinNode,*BinTree;
BinTree MakeTree(BinTree T,int n)
{
	 int i,x;
	 for(i=0;i<n;i++)
	 {
	  scanf("%d",&x);
	  Insert(T,x);
	 }
	 return T;
}
void Insert(BinTree T,int x)
{
	 BinNode *s=malloc(sizeof(struct node));
	 s->data=x;
	 s->lchild=NULL;
	 s->rchild=NULL;
	 if(T==NULL)
	 T=s;
	 if(T->lchild==NULL && x<T->data)
	 T->lchild=s;
	 if(T->rchild && x>T->data)
	 T->rchild=s;
	 if(x<T->data)
	 Insert(T->lchild,x);
	 if(x>T->data)
	 Insert(T->rchild,x);
}
void PreOrder(BinTree T,int n,int b[])
{
 	int a[N],i=0;
 	if(T==NULL)
 	{
	  int k;
	  for(k=0;k<n;k++)
	  {
	   if(a[k]!=b[k])
	   break;
	  }
	  if(k==n)
	  {
	   printf("YES\n");
	   return;
	  }
	  else
	  {
	   printf("NO\n");
	   return;
	  }
 }
 else{
  while(i<n){
   a[i]=T->data;
   i++;
   PreOrder(T->lchild,n,b);
   PreOrder(T->rchild,n,b);
  }
 }
}
void PostOrder(BinTree T)
{
	 if(T==NULL)
	 return;
	 else
	 {
	  PostOrder(T->lchild);
	  PostOrder(T->rchild);
	  printf("%d ",T->data);//´ýÐÞ¸Ä 
	 }
}
int main(int argc, char *argv[])
{
	int n,i,b[N];
	BinTree T;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&b[i]);
	}
 	MakeTree(T,n);
 	PreOrder(T,n,b);
 	PostOrder(T);
 	return 0;
}
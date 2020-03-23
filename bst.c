
#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *newNode(char item)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data=item;
    t->left=t->right=NULL;
}

struct node* insert(struct node* node, char data )
{
    if(node==NULL)
    {
        return newNode(data);
    }

    if(data < node->data)
    {
        node->left=insert(node->left,data);
    }
    else if(data> node->data)
    {
        node->right=insert(node->right,data);
    }

    return node;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%c ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ",root->data);
    }
}


int cmp(char str1[],char str2[])
{
	int l1,l2;
	for (l1 = 0; str1[l1] != '\0'; ++l1);
	for (l2 = 0; str2[l2] != '\0'; ++l2);
	
	int i,j=0;
	if(l1==l2)
	{
	   for(i=0;i<l1;i++)
	    {
		  if(str1[i]>str2[i])
		    {
			   j=1;
			   break;
		    }
		  else if((str1[i]<str2[i]))
		    {
			   j=-1;
			   break;	
		    }  
	    }
   }
   else if(l1>l2)
   {
   	 j=1;
   }
   else {
   	j=-1;
   }
   
   return j;
	
	
}


int main()
{
	int i,l1,l2;
	char str1[100],str2[100];
	printf("ENTER THE FIRST STRING ");
	scanf("%s",str1);
	
	printf("ENTER THE SECOND STRING ");
	scanf("%s",str2);
	
	printf("%s\n",str1);
	printf("%s\n",str2);
	
	for (l1 = 0; str1[l1] != '\0'; ++l1);
	for (l2 = 0; str2[l2] != '\0'; ++l2);
	
	
	struct node *root1 = NULL;
    root1=insert(root1,str1[0]);
    
    struct node *root2 = NULL;
    root2=insert(root2,str2[0]);
    
    for(i=1;i<l1;i++)
	{
		insert(root1,str1[i]);	
	}
	
	for(i=1;i<l2;i++)
	{
		insert(root2,str2[i]);	
	}
	
	printf("THE INORDER ARE:\n");
    inorder(root1);
    printf("\n");
    inorder(root2);
    printf("\n");
    
    printf("THE PRE ORDER ARE:\n");
    preorder(root1);
    printf("\n");
    preorder(root2);
    printf("\n");
	
	printf("THE POST ORDER ARE:\n");
    postorder(root1);
    printf("\n");
    postorder(root2);
    printf("\n");
    
    int r= cmp(str1,str2);
    printf("\nTHE STRINGS ARE\n",r);
    printf("%d",r);
    
    
}


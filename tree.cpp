#include <iostream>

#define MaxTree 10
#define ElementType char
#define Tree int
#define  Null -1


struct TreeNode
{
   char Element;
   int left;
   int right;
}T1[MaxTree],T2[MaxTree];

int Buildtree(TreeNode T[]);
int Isomorphic(int R1,int R2);

int main()
{
int R1,R2;

R1=Buildtree(T1);
R2=Buildtree(T2);

if (Isomorphic(R1,R2))
std::cout<<"Yes";
else
std::cout<<"NO";

return 0;
}

int Buildtree(TreeNode T[])
{
int N;
int root;
std::cin>>N;
int check[N]={};
for(int i=0;i<N;i++)
check[i]=0;
for(int i=0;i<N;i++)
{
std::cin>>T[i].Element>>T[i].left>>T[i].right;
if(T[i].left!='-')
check[i]=1;   
else
T[i].left=Null;

if(T[i].right!='-')
check[i]=1;   
else
T[i].right=Null;
}

for(int i=0;i<N;i++)
{
   if (!check[i])
   {
   int root = i;
   break;
   }
   else
   root = Null;
}
return root ;
}

int Isomorphic(int R1,int R2)
{
if((R1==Null) && (R2==Null))  //先考虑是否都为空
  return 1;
if((R1!=Null)&&(R2==Null) || (R1==Null) && (R2!=Null)) 
  return 0;
if(T1[R1].Element!=T2[R2].Element)
  return 0;
if ((T1[R1].left==Null) && (T2[R2].left==Null))
    return Isomorphic(T1[R1].right,T2[R2].right);

if ((T1[R1].left!=Null) && (T2[R2].left!=Null) && T1[R1].Element==T2[R2].Element)
   return Isomorphic(T1[R1].left,T2[R2].left)&&Isomorphic(T1[R1].right,T2[R2].right);
else
    return Isomorphic(T1[R1].left,T2[R2].right)&&Isomorphic(T1[R1].right,T2[R2].left);

}
   


  





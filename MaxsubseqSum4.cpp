#include<iostream>
int onlineprocessing(int A[],int N);

int main()
{
   int N;
   std::cin>>N;
   int A[N];
   for (int i=0;i<N;i++)
        std::cin>>A[i];
   int maxsum;
   maxsum=onlineprocessing(A,N);
   std::cout<<maxsum<<std::endl;
return 0;
}



int onlineprocessing(int A[],int N)
{
int thissum=0,maxsum=0;
for(int i=0;i<N;i++)
  {
    thissum+=A[i];
    if  (thissum>maxsum)
        maxsum=thissum;
    else if (thissum<0)
        thissum=0;
  }  
return maxsum;

}
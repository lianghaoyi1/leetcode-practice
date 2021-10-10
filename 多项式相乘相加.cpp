#include <iostream>
using namespace std;

typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;
    int expon;
    Polynomial next;
};


Polynomial ReadPoly();
Polynomial Mult(Polynomial A,Polynomial B);
Polynomial Sum( Polynomial A,Polynomial B);
void PrintPoly(Polynomial p);
void attach(int c,int e,Polynomial *pRear) ;
int main()
{
  Polynomial P1,P2,PP,PS;
  P1 = ReadPoly();
  P2 = ReadPoly();
  PP = Mult(P1,P2);
  PS = Sum(P1,P2);
  PrintPoly(PP);
 PrintPoly(PS);
 
}

Polynomial ReadPoly()  //新建并写入多项式函数
{
  Polynomial p,rear,t;
   p=(Polynomial)malloc(sizeof(PolyNode));
   p->next = NULL;
   rear=p;
  int N;
  int c,e;
  cin>>N;
  for(int i=0;i<N;i++)
  {
    cin>>c>>e;
    attach(c,e,&rear);
  }
  t=p;
  p=t->next;
  free(t);
  return p;

}

Polynomial Mult(Polynomial A,Polynomial B) //定义多项式相乘函数
{
   Polynomial p,p1,t,t1,t2,rear;
   t1=A;
   t2=B;
    int c,e;
   if (!t1||!t2)
   return NULL;
   
   p=(Polynomial)malloc(sizeof(PolyNode));
   rear=p;
   p1=p;
   while(t2)
   {
    attach(t1->coef*t2->coef,t1->expon+t2->expon,&rear);
    t2=t2->next;
   }
   t1=t1->next;
   while (t1)
   {
     t2=B;rear=p;
     while(t2)
     {
       c =t1->coef*t2->coef;
       e = t1->expon+t2->expon;
       while(rear->next&&rear->next->expon>e)
       rear=rear->next;
       if(rear->next==NULL)
         attach(c,e,&rear);
       else if(rear->next->expon<e)
         {t=(Polynomial)malloc(sizeof(PolyNode));
         t->coef=c;  t->expon=e;
         t->next=rear->next;
         rear->next=t;
         rear=t;
         }
       else          //rear->next->expon=e
        {
          if (rear->next->coef+c)
          {
            rear->next->coef+=c;
          }
          else
          {
            t=rear->next;
            rear->next=t->next;
            free(t);
          } 
        }
       
       t2=t2->next;
     }
     t1=t1->next;
   }
  
   p=p1->next;
   free (p1);
   return p ;
}

Polynomial Sum( Polynomial A,Polynomial B)//定义多项式相加函数
{
   Polynomial t1=A,t2=B;
   Polynomial p,t,rear;
   p=(Polynomial)malloc(sizeof(PolyNode));
   t=p;
   rear=p;
  

   while(t1&&t2)
   {
     if(t1->expon>t2->expon)
     {
       attach(t1->coef,t1->expon,&rear);
       t1=t1->next;
     }
    if(t2->expon>t1->expon)
     {
       attach(t2->coef,t2->expon,&rear);
       t2=t2->next;
     }
     if(t1->expon==t2->expon)
     {
       if(t1->coef+t2->coef!=0)
       {
        attach(t1->coef+t2->coef,t2->expon,&rear);
        t1=t1->next;
        t2=t2->next;
       }
       else
       {
         t1=t1->next;
        t2=t2->next;
        }

     }
   }
    if(t1==NULL)
    {
      while (t2)
      {
        attach(t2->coef,t2->expon,&rear);
        t2=t2->next;
      }
    }
    if(t2==NULL)
    {
      while(t1)
      {
        attach(t1->coef,t1->expon,&rear);
        t1=t1->next;
      }
    }
    p=t->next;
    free(t);
    return p;
}


void  PrintPoly(Polynomial p)
{
   if(!p)
   {
     std::cout<<0<<' '<<0<<endl;
     return;
    }
   int flag = 0;
  while(p)
  {
    if(!flag)
    {
      flag = 1;
      std::cout<<p->coef<<' '<<p->expon;
    }
    else
    std::cout<<' '<<p->coef<<' '<<p->expon;

    p=p->next;
  }
  std::cout<<endl;
  return ;
}

void attach(int c,int e,Polynomial *pRear) 
{
  Polynomial p ;
   p=(Polynomial)malloc(sizeof(PolyNode));
   p->coef = c;
   p->expon = e;
   p->next=NULL;
   (*pRear)->next =p;
   *pRear = p;
}
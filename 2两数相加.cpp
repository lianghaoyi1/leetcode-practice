/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head,*p,*q;
        head = new ListNode(0);
        p=head;
        int carry=0;
        while(l1||l2){
        if(l1&&l2)
        {
         q=new ListNode(0);
         q->val=(l1->val+l2->val+carry)%10;   
         if(l1->val+l2->val+carry>=10)
         carry=1;
         else
         carry=0;
         l1=l1->next;
         l2=l2->next;
         p->next=q;
         p=p->next;
        }
        else if(l1&&(!l2))
        {
           q=new ListNode(0);
           q->val=(l1->val+carry)%10;
         if(l1->val+carry>=10)
         carry=1;
         else
         carry=0;
         l1=l1->next;
         p->next=q;
         p=p->next;
        }
        else if(l2&&(!l1))
        {
           q=new ListNode(0);
           q->val=(l2->val+carry)%10;
         if(l2->val+carry>=10)
         carry=1;
         else
         carry=0;
         l2=l2->next;
         p->next=q;
         p=p->next;
        }
        
        
        if (carry==1)
            {
                q=new ListNode(1);
                p->next=q;
            }
        
        }
        return head->next;
    }
};



//还可以把链表中的数据取出变成数字，再放回链表中

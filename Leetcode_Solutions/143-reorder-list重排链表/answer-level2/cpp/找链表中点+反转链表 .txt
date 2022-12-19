```
class Solution {
public:
    void reorderList(ListNode* head) {
      if(head==0)return;
      auto mid=findMid(head);
      auto p=reverseList(mid->next); 
      mid->next=0;
        while(p)
        {
            auto temp1=p->next;
            auto temp2=head->next;
            head->next=p;
            p->next=temp2;
            head=temp2;
            p=temp1;  
        }   
    }
    
  ListNode* reverseList(ListNode* head)    //反转链表
  {                  
       if(head==0)return head;
       auto pre=head;
       head=head->next;
       pre->next=0;
        while(head)
        {
          auto temp=head->next;
          head->next=pre;
          pre=head;
          head=temp;
        }
       return pre;    
    }
    
  ListNode* findMid(ListNode* head)       //找链表中间节点
  {
      auto fast=head,slow=head;
      while(fast&&fast->next)
      {
          fast=fast->next->next;
          slow=slow->next;
      }
      
      return slow;   
  }   
};
```

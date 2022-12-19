### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rear=NULL;
        ListNode* result= NULL;
        ListNode* temp;
        
        int jinwei=0;
        for(;l1!=NULL&&l2!=NULL;l1=l1->next,l2=l2->next)
        {
            if((l1->val+l2->val+jinwei)>=10)
           {
               temp=new ListNode((l1->val+l2->val+jinwei)%10);
               jinwei=1;
           }
           else
           {
                temp=new ListNode((l1->val+l2->val+jinwei));
                jinwei=0;
           }
           if (result==NULL)
           {
               result=rear=temp;
           }
           else
           {
               rear->next=temp;
               rear=temp;
           }
        } 
        while(l1!=NULL)
        {
             if((l1->val+jinwei)>=10)
           {
               temp=new ListNode((l1->val+jinwei)%10);
               jinwei=1;
           }
           else
           {
               temp=new ListNode((l1->val+jinwei));
               jinwei=0;
           }
            l1=l1->next;
            rear->next=temp;
            rear=temp;   
        }
         while(l2!=NULL)
        {
             if((l2->val+jinwei)>=10)
           {
               temp=new ListNode((l2->val+jinwei)%10);
               jinwei=1;
           }
           else
           {
                 temp=new ListNode((l2->val+jinwei));
                 jinwei=0;
           }
           l2=l2->next;
           rear->next=temp;
           rear=temp; 
        }  
        if(l1==NULL&&l2==NULL&&jinwei!=0)
        {
              temp=new ListNode(1);
              jinwei=0;
              rear->next=temp;
              rear=temp;
        }
        
        return result;
        
    }
};
```
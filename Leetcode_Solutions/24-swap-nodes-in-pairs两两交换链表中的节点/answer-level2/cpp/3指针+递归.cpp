
```
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* p1,*p2,*p3;
        if(head)
        p1=head;
        else
        return NULL;
        if(p1->next)
        p2=p1->next;
        else
        return p1;
        if(p2->next)
        p3=p2->next;
        else
        {
            p2->next=p1;
            p1->next=0;
            return p2;
        }
        p2->next=p1;
        p1->next=swapPairs(p3);
        return p2;        
    }
};
```

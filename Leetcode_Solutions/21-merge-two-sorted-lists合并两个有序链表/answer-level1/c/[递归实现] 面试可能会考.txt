```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if(!l1) return l2;
       if(!l2) return l1;
        ListNode dummy(-1);
       ListNode* final=&dummy;
       if(l1->val<=l2->val)
       {
           final->next=l1;
           final=final->next;
           final->next=mergeTwoLists( l1->next, l2);
       }
        else
        {
            final->next=l2;
           final=final->next;
            final->next=mergeTwoLists( l1, l2->next);
        }
        return final;
    }
};
```

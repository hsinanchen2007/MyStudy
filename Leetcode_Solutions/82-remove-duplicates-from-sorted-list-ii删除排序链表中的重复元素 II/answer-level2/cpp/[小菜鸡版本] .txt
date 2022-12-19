```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;    
        ListNode dummy(INT_MIN);
        ListNode* prev=&dummy;
        dummy.next=head;
        ListNode* curr=head,*next=nullptr;
        while(curr)
        {
            next=curr?curr->next:nullptr;
            bool dupllicate=false;
            while(next && curr->val==next->val)
            {
                dupllicate=true;
                next=next?next->next:nullptr;
            }
            if(dupllicate)
            {
                prev->next=next;
                curr=next;  
            }
            else
            {
                prev=curr;
                curr=next;
            }            
        }
        return dummy.next;
    }
};
```

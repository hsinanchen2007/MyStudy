```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode h(-1),*p;
        h.next=head;                            //记录表头
        for(p=head->next;p!=NULL;p=p->next){
            if(head->val!=p->val) head=p;
            else
                head->next=p->next;
        }
        return h.next;
    }
};
```

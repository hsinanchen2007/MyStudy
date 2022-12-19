```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode  *H = new ListNode(-1);
        H->next      = head;
        ListNode **p = &(H->next);
        ListNode **e = NULL;
        while(*p&&(e=p)){
            while(*e && (*p)->val == (*e)->val){
                e = &(*e)->next;
            }
            if(e == &(*p)->next){
                p  = e;
            }else{
                *p = *e;
            }
        }
        return H->next;
    }
};
```

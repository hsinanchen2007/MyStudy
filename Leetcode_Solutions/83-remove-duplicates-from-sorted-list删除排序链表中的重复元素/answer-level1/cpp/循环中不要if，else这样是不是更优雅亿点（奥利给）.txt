```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode **__tmp = &head;
        ListNode **__t   = NULL;
        while(*__tmp &&(__t = __tmp)){
            while(*__t && (*__tmp)->val == (*__t)->val){
                __t = &(*__t)->next;
            }
            (*__tmp)->next = *__t;
            __tmp          =  __t;
        }
        return head;
    }
};
```

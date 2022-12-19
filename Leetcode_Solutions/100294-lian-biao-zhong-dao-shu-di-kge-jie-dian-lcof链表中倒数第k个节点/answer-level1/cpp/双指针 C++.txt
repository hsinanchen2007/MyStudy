快指针先走k步，然后快慢指针同时走，相距k，快指针走到队尾时，慢指针走到倒数第k个节点
```
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head) return head;
        ListNode* p = head;
        while(p && k--){ //快指针先走k步
            p = p->next;
        }
        while(p){ //快指针与慢指针的间距始终为k
            head = head->next; //当快指针走到队尾时
            p = p->next; //慢指针走到倒数第k个节点
        }
        return head;
    }
};
```

```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {    
        ListNode* preNode = nullptr;
        ListNode* p = head;
        n = n-m;
        while(--m){
            preNode = p;
            p = p->next;
            
        }
        ListNode* partOneTail = preNode;
        ListNode* partTwoTail = p;
        preNode = p;
        p = p->next;
        while(n){
            ListNode* nextNode = p->next;
            p->next = preNode;
            preNode = p;
            p = nextNode;
            --n;
        }
        if(!partOneTail){
            head = preNode;
        }
        else{
            partOneTail->next = preNode;
        }
        partTwoTail->next = p;
        return head;
    }
};
```

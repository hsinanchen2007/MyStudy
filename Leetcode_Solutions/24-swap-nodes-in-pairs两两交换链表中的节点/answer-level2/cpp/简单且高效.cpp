```cpp
class Solution {
private:
    ListNode target{0};
    ListNode* newHead = &target;
    
public:
    ListNode* swapPairs( ListNode* head ) {
        if ( !head or !head->next) return head;
        
        ListNode* res = newHead;
        newHead->next = head;
        
        ListNode* p = head;
        while ( p and p->next ) {
            newHead->next = swap(p, p->next);
            newHead = newHead->next->next;
            p = newHead->next;
        }
        
        newHead = &target;
        return res->next;
    }
    
    ListNode* swap(ListNode* a, ListNode* b) {
        a->next = b->next;
        b->next = a;
        return b;
    }

};
```
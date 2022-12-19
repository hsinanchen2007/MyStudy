```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        ListNode* p1 = headA, * p2 = headB;
        while(p1 != p2) {
            if(!p1) p1 = headB;
            else p1 = p1->next;
            
            if(!p2) p2 = headA;
            else p2 = p2->next;
        }
        return p1;
    }
};
```

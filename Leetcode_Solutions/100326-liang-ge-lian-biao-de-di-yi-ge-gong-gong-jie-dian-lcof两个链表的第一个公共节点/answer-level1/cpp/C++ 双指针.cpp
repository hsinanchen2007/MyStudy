```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA, *nodeB = headB;
        while (nodeA != nodeB) {
            nodeA = (nodeA == nullptr ? headB : nodeA->next);
            nodeB = (nodeB == nullptr ? headA : nodeB->next);
        }
        return nodeA;
    }
};
```
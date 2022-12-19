```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    while (headA != NULL) {
        struct ListNode* temp = headB;
        while (temp != NULL) {
            if (headA == temp) {
                return headA;
            }
            temp = temp->next;
        }
        headA = headA->next;
    }
    return NULL;
}
```
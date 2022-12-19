### 解题思路
注意此处的相交是内存相交，而不单单指元素相同的相交。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* A = NULL;
    struct ListNode* B = NULL;
    struct ListNode* finalNode = NULL;
    struct ListNode* C = NULL;
    struct ListNode* D = NULL;

    if  ((headA == NULL) || (headB == NULL)) {
        return NULL;
    }
    
    for (A = headA; A != NULL; A = A->next) {
        for (B = headB; B != NULL; B = B->next) {
            if (A == B) {
                finalNode = A;
            }
        }
        if (finalNode != NULL) {
            break;
        }
    }
    return finalNode;

}
```
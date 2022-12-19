### 解题思路
此处撰写解题思路

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
    struct ListNode *bakA = headA;
    struct ListNode *bakB = headB;

    int flagA = 0;
    int flagB = 0;

    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    
    while (headA != headB) {
        headA = headA->next;
        if (headA == NULL && flagA == 0) {
            headA = bakB;
            flagA = 1;
        }

        headB = headB->next;
        if (headB == NULL && flagB == 0) {
            headB = bakA;
            flagB = 1;
        }
    }

    if (headA == NULL) {
        return NULL;
    }

    return headA;
}
```
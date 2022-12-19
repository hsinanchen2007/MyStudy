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
    if (!headA || !headB) {
        return NULL;
    }
    struct ListNode *pa = headA;
    struct ListNode *pb = headB;

    while (pa != pb) {
        pa = (pa ? pa->next : headB);
        pb = (pb ? pb->next : headA);
    }

    return pa;
}
```
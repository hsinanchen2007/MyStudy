### 解题思路
1. 经典做法，求出两个链表长度，让长链表先走长度差，然后同时走，走到指针地址相同的地方就是公共头指针

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
    struct ListNode *pa = headA;
    struct ListNode *pb = headB;
    int counta = 0, countb = 0;
    int i;

    while (pa != NULL)
    {
        pa = pa->next;
        counta++;
    }
    while (pb != NULL)
    {
        pb = pb->next;
        countb++;
    }

    pa = headA;
    pb = headB;
    if (counta > countb) for (i = 0; i < counta - countb; i++) pa = pa->next;
    else for (i = 0; i < countb - counta; i++) pb = pb->next;

    while (pb != pa)
    {
        pa = pa->next;
        pb = pb->next;
    }
    return pa;
}
```
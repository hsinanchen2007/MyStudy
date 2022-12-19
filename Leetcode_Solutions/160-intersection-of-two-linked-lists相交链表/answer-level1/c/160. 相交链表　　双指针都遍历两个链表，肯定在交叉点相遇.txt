### 解题思路
编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：



在节点 c1 开始相交。

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
    struct ListNode * tempa = headA;
    struct ListNode * tempb = headB;
    int counta = 0, countb = 0;

    while(tempa != tempb) {
        if (!tempa) {
            tempa = headB;
            counta++;
            if(counta == 2)
                return NULL;
        } else {
            tempa = tempa->next;
        }

        if (!tempb) {
            tempb = headA;
            countb++;
            if (counta == 2)
                return NULL;
        } else
            tempb = tempb->next;
    }
    return tempa;
}
```
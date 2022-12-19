### 解题思路
***思路1：将两个链表增/减至相同的长度，再逐个结点比较。***
1）分别求取两个链表的长度；
2）根据求得的两个链表的长度，分别增/减链表，使两个链表长度一致；
3）逐个迭代，直到找到两个链表中相同的结点，
**注意：是两个相同的结点，不是两个结点对应的值相同。**

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 求链表长度
int calLinkLength(struct ListNode *head)
{
    struct ListNode *p = head;
    int linkLength = 0;

    while (p != NULL) {
        p = p->next;
        linkLength++;
    }

    return linkLength;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if ((headA == NULL) || (headB == NULL)) {
        return NULL;
    }

    int nodeALen = 0;
    int nodeBLen = 0;
    struct ListNode *tempA = headA;
    struct ListNode *tempB = headB;

    nodeALen = calLinkLength(tempA);
    nodeBLen = calLinkLength(tempB);

    while (nodeALen > nodeBLen) {
        tempA = tempA->next;
        nodeALen--;
    }
    while (nodeALen < nodeBLen) {
        tempB = tempB->next;
        nodeBLen--;
    }

    while (tempA != tempB) {
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return tempA;
}
```
### 解题思路
详见代码（8用我多说了8）
![捕获.PNG](https://pic.leetcode-cn.com/c4e455afe7f0c16254a75c74f3592ac889bdde4311f5cd3eae76a6f0fd6ac331-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    int lenA = 0, lenB = 0;
    ListNode *p = headA, *q = headB;
    while (p != NULL) {lenA++; p = p->next;}
    while (q != NULL) {lenB++; q = q->next;}
    p = headA, q = headB;
    while (p != NULL && lenA > lenB) {p = p->next; lenA--;}
    while (q != NULL && lenB > lenA) {q = q->next; lenB--;}
    while (p != NULL && q != NULL) {
    if (p == q) return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}
```
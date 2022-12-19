大家可以先看一下官方题解中思路，在看我的程序比较好
```
struct ListNode *detectCycle(struct ListNode *pHead) {
    if (pHead == NULL || pHead->next == NULL) return NULL;
    struct ListNode *fast = pHead;
    struct ListNode *slow = pHead;
    do {
        slow = slow->next;
        if (fast->next == NULL || fast->next->next == NULL) return NULL;
        else fast = fast->next->next;
    }while (slow != fast);
    slow = pHead;
    while (fast != slow) slow = slow->next, fast = fast->next;
    return fast;
}
```

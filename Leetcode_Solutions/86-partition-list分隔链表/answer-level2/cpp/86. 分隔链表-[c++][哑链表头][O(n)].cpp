这种来回切来切去的，弄个『哑链表头』最好了。

```cpp
ListNode* partition(ListNode* head, int x) {
    ListNode dummyHeadLeft(0), dummyHeadRight(0);
    auto p = &dummyHeadLeft;
    auto q = &dummyHeadRight;
    while (head) {
        if (head->val < x) {
            p->next = head;
            p = head;
        } else {
            q->next = head;
            q = head;
        }
        head = head->next;
    }
    q->next = nullptr; // 必须，否则链表成环
    p->next = dummyHeadRight.next;
    return dummyHeadLeft.next;
}
```

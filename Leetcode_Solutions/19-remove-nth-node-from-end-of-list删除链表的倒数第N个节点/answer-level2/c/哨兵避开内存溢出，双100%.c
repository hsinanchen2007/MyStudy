执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.5 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (n <= 0) {
        return 0;
    }
    struct ListNode *first, *second, *ret;
    ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    first = ret;
    second = ret;
    ret->next = head;
    first->next = head;
    second = head;
    while (n > 0) {
        second = second->next;
        n--;
    }
    while (second != NULL) {
        first = first->next;
        second = second->next;
    }
    first->next = first->next->next;
    return ret->next;
}
```
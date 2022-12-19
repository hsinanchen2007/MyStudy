执行结果：通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了88.45%的用户
内存消耗 :7.2 MB, 在所有 C 提交中击败了75.42%的用户

```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* tail = head;
    int i = 1;
    if (head == NULL) return NULL;
    
    while (i++ < n) {
        if (tail->next != NULL) tail = tail->next;
    }
    
    if (tail != NULL && tail->next == NULL) {
        tail = head;
        head = head->next;
        free(tail);
        return head;
    }
    struct ListNode* pre = head;
    tail = tail->next;
    
    while (tail->next != NULL) {
        tail = tail->next;
        pre = pre->next;
    }
    tail = pre->next;
    pre->next = tail->next;
    free(tail);
    
    return head;
}
```
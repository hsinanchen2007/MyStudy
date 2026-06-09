```
struct ListNode* __reverseList(struct ListNode* head, struct ListNode* pre){
    struct ListNode* tmp = head->next;
    head->next = pre;
    return tmp ? __reverseList(tmp, head) : head;
}

struct ListNode* reverseList(struct ListNode* head){
    return head ? __reverseList(head, NULL) : NULL;
}
```

递归写法, 使用一个辅助函数, 将结点的前驱指针传入, 提高了可读性
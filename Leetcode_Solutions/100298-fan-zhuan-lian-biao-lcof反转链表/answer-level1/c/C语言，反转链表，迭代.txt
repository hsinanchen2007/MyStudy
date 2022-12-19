```
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    struct ListNode* temp = NULL;
    while(cur){
        temp = cur->next;
        cur->next = pre;//开始迭代反转
        pre = cur;
        cur = temp;
    }
    return pre;
}
```

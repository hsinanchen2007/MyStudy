思路和解法和“删除链表中等于给定值 val 的所有节点”这道题一毛一样~

```c
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL)return head;
    struct ListNode *first = (struct ListNode*)malloc(sizeof(struct ListNode));
    first->next = head;
    head  = first;
    struct ListNode *p = first->next;
    struct ListNode *pre = first;
    while(p){
        if(p->val == pre->val){
            pre->next = p->next;
            free(p);
            p = pre;
        }
        pre = p;
        p = p->next;
    }
    return head->next;
}
```


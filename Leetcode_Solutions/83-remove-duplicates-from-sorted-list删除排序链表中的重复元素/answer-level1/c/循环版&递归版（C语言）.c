C语言实现循环版
```
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* cur;
    cur = head;
    while(cur != NULL && cur->next != NULL)
    {
        if(cur->val == cur->next->val)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return head;
}
```

递归版
```
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;    
    if(head->val == head->next->val)
        return deleteDuplicates(head->next);
    else
    {   
        head->next = deleteDuplicates(head->next);
        return head;
    }
}
```

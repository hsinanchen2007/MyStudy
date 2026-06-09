考察的是对链表的基本操作，不多做赘述直接上代码。

```
struct ListNode* deleteDuplicates(struct ListNode* head){
    //空链表情况
    if (!head)
        return NULL;
    
    struct ListNode* cur = head, *pre = head->next;
    while(pre)  //非空链表，包括只有一个节点的情况。
    {
        if(cur->val == pre->val)
        {
            cur->next = pre->next;
            free(pre);
            pre = cur->next;
        }
        else
        {
            cur = cur->next;
            pre = pre->next;
        }
    }

    return head;
}
```

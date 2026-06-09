为了方便，创建一个头节点指向链表头部。后续代码较为常规，不再赘述。
```c
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode header;
    header.next=head;
    struct ListNode *end=head;
    head=&header;
    while(head->next){
        while(end&&end->val==head->next->val) end=end->next;
        if(end!=head->next->next) head->next=end;
        else head=head->next;
    }
    return header.next;
}
```
- 头插法，不需要额外的空间
```
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* p = head;
    struct ListNode* q = NULL;
    if(head == NULL){
        return NULL;
    }
    while(p -> next != NULL){
        struct ListNode* tmp = p -> next;
        p -> next = q;
        q = p;
        p = tmp;
    }
    p -> next = q;
    q = p;
    return q;
}
```

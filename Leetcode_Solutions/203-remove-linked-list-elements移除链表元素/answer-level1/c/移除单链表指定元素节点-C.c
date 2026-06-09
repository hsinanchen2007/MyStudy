```c
struct ListNode* removeElements(struct ListNode* head, int val){
    if(head == NULL) return head;
    
    struct ListNode* p = head;
    
    // 移动头部，保证第一个值不为val
    while (p->val == val){
        if(p->next==NULL){
            return NULL;
        }
        p = p->next;
    }
    
    head = p;
    
    while(p!=NULL&&p->next!=NULL){
        if(p->next!=NULL&&p->next->val == val){
            p->next = p->next->next;
        }
        else p = p->next;
    }
    
    return head;
}
```

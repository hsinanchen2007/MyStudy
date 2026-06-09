C语言实现
```C []
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head;
    while (p && p->next){
        if (p->val == p->next->val){
            p->next = p->next->next;
        }else{
            p = p->next;
        }
    }
    return head;
}
```
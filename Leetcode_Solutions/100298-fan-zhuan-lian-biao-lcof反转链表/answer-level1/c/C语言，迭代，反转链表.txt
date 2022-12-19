```
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* p = head;
    struct ListNode* r = NULL;
    if(!p||!p->next){
        return head;//链表为空链表或者只有一个结点时，无需反转
    }else{
        struct ListNode* q = head->next;
        p->next = NULL;//原先的头结点作新链表的尾结点
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
    }
    head = p;
    return head;
}
```

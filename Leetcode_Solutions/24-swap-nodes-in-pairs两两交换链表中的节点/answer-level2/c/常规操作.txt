多申请了一个头结点
```
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode * preHead = (struct ListNode *)malloc (sizeof(struct ListNode));
    preHead->next = head;    
    struct ListNode * p = preHead;
    struct ListNode * q = NULL;

    while (p->next != NULL && p->next->next != NULL) {
        q = p->next;
        p->next = p->next->next;
        q->next = p->next->next;
        p->next->next = q;
        p = p->next->next;
    }

    return preHead->next;
}
```

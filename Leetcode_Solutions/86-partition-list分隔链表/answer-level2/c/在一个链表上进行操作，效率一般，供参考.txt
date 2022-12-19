```
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode * preHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * p       = NULL;
    struct ListNode * q       = NULL;
    struct ListNode * t       = NULL;

    if (head == NULL) {
        return head;
    }

    preHead->next = head;
    p = preHead;

    while (p->next != NULL) {
        if (p->next->val >= x) {
            break;
        }
        p = p->next;
    }

    if (p->next == NULL) {
        return head;
    }
    q = p->next;
    while (q != NULL && q->next != NULL) {
        if (q->next->val < x) {
            t       = q->next;
            q->next = t->next;
            t->next = p->next;
            p->next = t;
            p       = p->next;
        } else {
            q = q->next;
        }    
    }
    return preHead->next;
}
```

```
struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode * preHead    = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * p          = NULL;
    int               i;
    int               listLength = 1;
    int               moveDis    = 0;
    if (head == NULL || k == 0) {
        return head;
    }
    preHead->next = head;
    p             = preHead->next;
    /* 先首尾相连 */
    while (p->next != NULL) {
        p = p->next;
        listLength ++;
    }
    p->next = preHead->next;
    moveDis = listLength - k % listLength;
    for (i = 0; i < moveDis; i++) {
        preHead->next = preHead->next->next;
        p = p->next;
    }
    p->next = NULL;
    return preHead->next;
}
```

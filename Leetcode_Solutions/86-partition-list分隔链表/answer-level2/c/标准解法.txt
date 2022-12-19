```
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode * pre    = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * aft    = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * preCur = pre;
    struct ListNode * aftCur = aft;

    while (head != NULL) {
        if (head->val < x) {
            preCur->next = head;
            preCur       = preCur->next;
        } else {
            aftCur->next = head;
            aftCur       = aftCur->next;
        }
        head = head->next;
    }

    aftCur->next = NULL;
    preCur->next = aft->next;
    
    return pre->next;
}
```

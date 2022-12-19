```
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode * preHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * curNode = NULL;
    struct ListNode * slowP   = NULL;
    struct ListNode * quickP  = NULL;
    int               n;

    preHead->next   = head;
    curNode         = preHead;
    slowP           = head;

    while (slowP != NULL) {
        for (n = 0,quickP = slowP->next; quickP != NULL; n++, quickP = quickP->next) {
            if (slowP->val != quickP->val) {
                break;
            }
        }
        if (n == 0) {
            curNode->next = slowP;
            curNode       = curNode->next;
        } else if (quickP == NULL) {
            curNode->next = NULL;
            break;
        }
        slowP = quickP;
    }
    return preHead->next;
}
```

```
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node ->next = head;
    struct ListNode* pre = node;
    while(pre ->next != NULL && pre -> next -> next != NULL){
        struct ListNode* L1 = pre ->next;
        struct ListNode* L2 = pre -> next -> next;
        struct ListNode* next = L2 -> next;
        L1 -> next = next;
        L2 -> next = L1;
        pre -> next = L2;
        pre = L1;
    }
    return node ->next;
}
```

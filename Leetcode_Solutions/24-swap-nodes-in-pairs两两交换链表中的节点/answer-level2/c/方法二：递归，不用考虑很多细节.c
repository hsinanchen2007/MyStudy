```
struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    struct ListNode* L1 = head;
    struct ListNode* L2 = head-> next;
    head = L2;
    L1 -> next = L2 -> next;
    L2 -> next= L1;
    L1 -> next= swapPairs(L1 -> next);
    return head;
}
```

```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* fst = head;
    struct ListNode* sec = head;
    while(n > 0){
        fst = fst -> next;
        n -= 1;
    }
    if(fst == NULL){
        return head -> next;
    }
    while(fst -> next != NULL){
        fst = fst -> next;
        sec = sec -> next;
    }
    sec -> next = sec -> next -> next;
    return head;
}
```

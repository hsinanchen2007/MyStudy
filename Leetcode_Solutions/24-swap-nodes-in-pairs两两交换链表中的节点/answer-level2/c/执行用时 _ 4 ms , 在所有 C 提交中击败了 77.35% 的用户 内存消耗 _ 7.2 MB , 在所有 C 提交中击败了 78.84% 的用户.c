```
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p1;
    struct ListNode **pp;
    
    p1 = head;
    pp = &head;
    while (p1 != NULL && p1->next != NULL) {
        struct ListNode *p2 = p1->next;
        *pp = p2;
        pp = &(p1->next);
        p1->next = p2->next;
        p2->next = p1;
        p1 = p1->next;
    }
    
    return head;
}


```

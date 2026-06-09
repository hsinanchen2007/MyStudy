```
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tmp = head;
    head -> next = NULL;
    while(l1 != NULL && l2 != NULL){
        if(l1 -> val <= l2 -> val){
            tmp ->next = l1;
            l1 = l1 -> next;
        }else{
            tmp ->next = l2;
            l2 = l2 -> next;
        }
        tmp = tmp -> next;
    }
    if(l1 != NULL){
        while(l1 != NULL){
            tmp ->next = l1;
            tmp = tmp -> next;
            l1 = l1 -> next;
        }
    }else if(l2 != NULL){
         while(l2 != NULL){
            tmp ->next = l2;
            tmp = tmp -> next;
            l2 = l2 -> next;
        }
    }
    return head -> next;
}
```

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L -> next = head;
    struct ListNode *front ,*back,*pre;
    if(head == NULL || head->next == NULL){
        return L->next;
    }
    front = head->next,back = head;
    pre = L;
    while(back != NULL && back->next != NULL){
        front = back->next;
        back ->next = front->next;
        pre -> next = front;
        front->next = back;
        pre = back;
        back = back->next;
    }
    return L->next;
}
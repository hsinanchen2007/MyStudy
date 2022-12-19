struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    struct ListNode* tmp = head->next;
    head->next = swapPairs(tmp->next);
    tmp->next = head;
    return tmp;
}
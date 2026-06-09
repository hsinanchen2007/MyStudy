struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *nextNode = NULL;
    struct ListNode *lastNode = NULL;

    if (head == NULL){
        return NULL;
    }
    nextNode = head->next;
    head->next = NULL;
    lastNode = head;

    while(nextNode != NULL){
        head = nextNode;
        nextNode = head->next;
        head->next = lastNode;
        lastNode = head;
    }

    return head;
}
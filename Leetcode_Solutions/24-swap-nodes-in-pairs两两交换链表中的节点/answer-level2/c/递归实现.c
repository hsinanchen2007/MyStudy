struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* temp = head->next;
    head->next = head->next->next;
    temp->next = head;
    head->next = swapPairs(head->next);
    return temp;
}
void deleteNode(struct ListNode* node) {
    struct ListNode *next = node->next->next;
    node->val = node->next->val;
    //free(node->next);
    node->next = next;
}
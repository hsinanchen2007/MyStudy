// 求链表长度
int getLengthOfList(ListNode *head) {
    if (head == nullptr)
        return 0;
    ListNode *pNode = head;
    int len = 1;
    while (pNode->next != nullptr) {
        len++;
        pNode = pNode->next;
    }
    return len;
}

// 求倒数第k个节点
ListNode* getKthFromEnd(ListNode* head, int k) {
    int len = getLengthOfList(head);
    if (len == 0 || k == 0 || k > len) return nullptr;
    ListNode *pNode = head;
    for (int i = 0; i < len - k; ++i) 
        pNode = pNode->next;
    return pNode;
}
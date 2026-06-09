struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *lastNode = head;
    struct ListNode *curNode = NULL;
    struct ListNode *nextNode = NULL;

    if (head == NULL || head->next == NULL){
        return head;
    }
    curNode = head;
    nextNode = curNode->next;
    //交换前两个节点的位置
    curNode->next = nextNode->next;
    nextNode->next = curNode;
    head = nextNode;
    lastNode = curNode;

    //交换接下来两个节点的位置
    while (lastNode->next != NULL && lastNode->next->next != NULL){
        curNode = lastNode->next;
        nextNode = curNode->next;

        curNode->next = nextNode->next;
        nextNode->next = curNode;
        lastNode->next = nextNode;

        lastNode = curNode;
    }

    return head;
}
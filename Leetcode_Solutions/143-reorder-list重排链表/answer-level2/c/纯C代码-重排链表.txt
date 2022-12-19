void reorderList(struct ListNode* head){
    struct ListNode *node = head;
    struct ListNode *address[50000] = {0};
    int i = 0;
    int num = 0;
    int tail = 0;

    if (node == NULL){
        return;
    }
    while (node != NULL){
        address[num++] = node;
        node = node->next;
    }
    
    node = head;
    i++;
    tail = num-i;
    while(i<num){
        node->next = address[--num];
        node = node->next;
        if (i >= num){
            break;
        }
        node->next = address[i++];
        node = node->next;
    }
    node->next = NULL;

    return;
}
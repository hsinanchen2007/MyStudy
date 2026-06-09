struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *tmp = head;
    int i = 0;

    if (tmp == NULL){
        return NULL;
    }
    //得到链表长度
    while(tmp != NULL){
        i++;
        tmp = tmp->next;
    }
    //计算删除节点前面节点的个数
    i = i-n;
    if (i==0){
        return head->next;
    }
    //找到删除节点的上一个节点的指针
    tmp = head;
    while(i>1){
        i--;
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;

    return head;
}
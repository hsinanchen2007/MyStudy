struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL)
        return NULL;
    struct ListNode *p = head;
    int len = 0;
    int i = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    if(len ==1)
        return NULL;
    p = head;
    head = p;
    if(len == n)
    {
        head = p->next;
    }
    for(i = 1;i < len - n;i++)
    {
        p = p->next;
    }
    if(p->next->next == NULL)
        p->next = NULL;
    else
    {
        p->next = p->next->next;
    }
    return head;
}
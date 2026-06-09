struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int count = 1;
    struct ListNode* p = head;
    while(p)
         {
        struct ListNode* q = p;
        for(count = 1;count <= n;count++)
        {    
            q = q->next;
        }
        if(!q)
            break;
        p = p->next;
    }
    if(p->next)
    {
        p->val = p->next->val;
        p->next = p->next->next;
    }
    else if( !(p->next))
        p = NULL;
    return head;
}
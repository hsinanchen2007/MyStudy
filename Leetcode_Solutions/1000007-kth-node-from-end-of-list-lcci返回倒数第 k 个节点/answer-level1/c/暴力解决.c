int kthToLast(struct ListNode* head, int k){
    struct ListNode *p=head;
    int n=1;
    while(p->next!=NULL)
    {
        p=p->next;
        n++;
    }
    p=head;
    while(k<n)
    {
        p=p->next;
        k++;
    }
    return p->val;
}
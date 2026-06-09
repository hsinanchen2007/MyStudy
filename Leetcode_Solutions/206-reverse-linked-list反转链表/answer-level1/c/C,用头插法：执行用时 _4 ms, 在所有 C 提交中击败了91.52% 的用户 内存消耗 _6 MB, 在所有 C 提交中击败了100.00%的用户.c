struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL){return NULL;}
    struct ListNode *p,*pnext;
    p=head->next;
    head->next=NULL;
    while(p){
        pnext=p->next;
        p->next=head;
        head=p;
        p=pnext;
    }
    return head;
}
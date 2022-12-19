struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p1,*p2;
    p1=head;
    if(p1==NULL || p1->next==NULL)
    {
        return head;
    }
    head=head->next;
    p2=head;
    while(p1->next!=NULL)
    {
        p1->next=p2->next;
        p2->next=p1;
        p1=p1->next;
        if(p1==NULL || p1->next==NULL)  //或运算解决奇偶问题，若是偶数则是第一个条件，若是奇数则是第二个条件
        {
            return head;
        }
        p2=p2->next;
        p2->next=p1->next;
        p2=p2->next;
    }
    return head;
}

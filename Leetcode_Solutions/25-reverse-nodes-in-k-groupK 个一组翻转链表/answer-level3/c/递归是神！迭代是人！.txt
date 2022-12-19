直接递归，模仿大牛代码！
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode* pr=head;
    struct ListNode* pk=head;
    int i=0;
    for(i=0;i<k&&pk;i++,pk=pk->next);  
    if(!pk && i<k)
    {
        return head; 
    }   
    struct ListNode* p=head;//待操作结点
    struct ListNode* q=NULL;//新链头结点
    struct ListNode* l=head;//新链尾结点
    while(p!=pk)
    {
        head=head->next;
        p->next=q;
        q=p;
        p=head;
    }       
    l->next=reverseKGroup(pk,k);
    return q;   
}
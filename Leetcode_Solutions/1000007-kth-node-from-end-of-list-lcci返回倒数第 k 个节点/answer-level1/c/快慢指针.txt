```
int kthToLast(struct ListNode* head, int k)
{
    struct ListNode *front=head,*back=head;
    for(int i=0;i<k;i++)
    {
        front=front->next;
    }
    while(front!=NULL)
    {
        front=front->next;
        back=back->next;
    }
    return back->val;
}
```

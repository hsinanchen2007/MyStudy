```C 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL)
        return head;
    struct ListNode *pcur=head;
    struct ListNode *pnext=head->next;
    while(pnext!=NULL)
    {
        if(pcur->val==pnext->val)
        {
            pcur->next=pnext->next;
            free(pnext);
            pnext=pcur->next;
        }
        else
        {
            pcur=pnext;
            pnext=pcur->next;
        }
    }
    return head;
}
```


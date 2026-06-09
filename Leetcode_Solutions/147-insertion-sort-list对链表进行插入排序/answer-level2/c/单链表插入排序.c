struct ListNode *insertionSortList(struct ListNode *head)
{
    struct ListNode *nook = head->next->next;
    head->next->next = NULL;
    while(nook != NULL)
    {
        struct ListNode *pre = head;
        struct ListNode *seq = head->next;
        struct ListNode *temp = nook;
        nook = nook->next;
        while(seq != NULL)
        {
            if(temp->val < seq->val)
            {
                temp->next = seq;
                pre->next = temp;
                break;
            }
            else if(seq->next == NULL)
            {
                seq->next = temp;
                temp->next = NULL;
                break;
            }
            else
            {
                seq = seq->next;
                pre = pre->next;
            }
        }
    }
    return head;
}
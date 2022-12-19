```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* h1 = NULL;
    struct ListNode* h2 = NULL;
    struct ListNode* pre = NULL;
    struct ListNode head;
    pre =&head;
    h1 = l1;
    h2 = l2;
    if(h1 == NULL && h2 ==NULL)
    {
        return h1;
    }
    while(h1 && h2)
    {
        if(h1->val < h2->val)
        {
            pre->next = h1;
            pre= pre->next;
            h1 = h1->next;
        }
        else
        {
            pre->next = h2;
            pre= pre->next;
            h2 = h2->next;
        }
    }
    while(h1 || h2 )
    {
    if(h1 == NULL)
    {
        pre->next =h2;
        pre= pre->next;
        h2 = h2->next;
    }
    else
    {
        pre->next =h1;
        pre= pre->next;
        h1 = h1->next;
    }
    }
    pre->next = NULL;
    return (&head)->next;
}
```

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* less_head= NULL;
    struct ListNode* more_head =NULL;
    struct ListNode mhead;
    struct ListNode lhead;
    less_head = &lhead;
    more_head = &mhead;

   if(head == NULL)
    {
        return head;
    }
    while(head != NULL)
    {
        if(head->val < x)
        {
            less_head->next = head;
            less_head = less_head->next;
        }
        else
        {
            more_head->next = head;
            more_head = more_head->next;
        }
        head =head->next;
    }
    more_head->next = NULL;//这个很重要，勿忘
    less_head->next = mhead.next;
    printf("%p %p",mhead.next,more_head->next);
    return lhead.next;

}
```
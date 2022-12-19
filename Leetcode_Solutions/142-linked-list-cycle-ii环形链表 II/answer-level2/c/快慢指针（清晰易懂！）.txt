```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow,*fast;
    slow=fast=head;

    if(!head||!(head->next))  return NULL;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) break;
    }    
    if(!fast||!(fast->next)) return NULL;
    else
    {
     slow=head;
    while(slow!=fast)
    {
            slow=slow->next;
            fast=fast->next;
    }
    return slow;
}
}
```

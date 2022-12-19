```
 ListNode* removeElements(ListNode* head, int val) 
{
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        head = newhead;
        while(head->next)
        {
            if(head->next->val==val)
                head->next = head->next->next;
            else
                head = head->next;
        }
        return newhead->next;
    }
```

```
ListNode* deleteNode(ListNode* head, int val) {
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        ListNode* p = pHead;
        while(p->next != NULL)
        {
            if(p->next->val == val)
            {
                ListNode * tmp = p->next;
                p->next = tmp->next;
                break;
            }
            p = p->next;
        }
        return pHead->next;
    }
```

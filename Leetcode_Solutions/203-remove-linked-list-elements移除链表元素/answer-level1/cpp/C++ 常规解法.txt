```
ListNode* removeElements(ListNode* head, int val) {
        while(head && head -> val == val) head = head -> next;
        if(!head) return head;
        ListNode *p = head ,*q = p -> next;
        while(q != NULL)
        {
            if(q -> val == val) p -> next = q -> next;
            else p = q;
            q = p -> next;
        }
        return head;
    }
```

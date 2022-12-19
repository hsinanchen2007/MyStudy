ListNode* rotateRight(ListNode* head, int k) {
        int index = 0, size = 0;
        
        ListNode* n = head;
        ListNode dummy(-1), *l = &dummy;
        
        while(n != NULL)
        {
            size++;
            n = n->next;
        }
        n = head;
        
        vector<int> v(size,0);
        
        while(n != NULL)
        {
            v[(index + k) % size] = n->val;
            n = n->next;
            index++;
        }
        
        for(auto i : v)
        {
            l->next = new ListNode(i);
            l = l->next;
        }
        
        return dummy.next;
    }
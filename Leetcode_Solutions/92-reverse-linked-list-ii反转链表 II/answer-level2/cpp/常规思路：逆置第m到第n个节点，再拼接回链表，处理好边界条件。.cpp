    if (n <= m  || head==NULL || head->next == NULL) return head;
        
        ListNode * node = head;
        ListNode * next = NULL;
        ListNode * pre = NULL;
        
        int i = 1;
        
        while( node && i < m)
        {
            pre = node;
            
            node = node->next;
            
            ++i;
        }
        
        ListNode * start = pre;
        ListNode * end = node;
        
        while( node && i <= n )
        {
            
            next = node->next;
            
            node->next = pre;
            
            pre = node;
            
            node = next;
            
            ++i;
        }
       
        if (start != NULL) 
        {
            start->next = pre;
        }
        else
        {
            head = pre;
        }
        
        end->next = node;
    
        return head;
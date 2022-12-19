    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1){
            return head;
        }
        ListNode* h = new ListNode(0);
        h->next = head;
        ListNode* preH = h; //每组翻转第一个结点的前一个结点
        ListNode* tail = NULL;//每组翻转的最后一结点
        int n = 0;
        //一边遍历一边翻转
        while(head){
            if (preH->next == head){
                tail = head;
                head = head->next;
            }
            else{
                tail->next = head->next;
                head->next = preH->next;
                preH->next = head;

                head = tail->next;
            }
            ++n;
            if (n == k){
                n = 0;
                preH = tail;
            }
        }
        //最后一组不足k，则翻转回来
        if (n > 1){
            ListNode* cur = preH->next;
            ListNode* hc = NULL;
            while(cur){
                ListNode* t = cur;
                cur = cur->next;

                t->next = hc;
                hc = t;
            }
            preH->next = hc;
        }
        return h->next;
    }
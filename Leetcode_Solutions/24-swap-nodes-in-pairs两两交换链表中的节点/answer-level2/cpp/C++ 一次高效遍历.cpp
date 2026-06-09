    ListNode* swapPairs(ListNode* head) {
        ListNode* l = new ListNode(0);
        l->next = head;
        ListNode* p = l;

        ListNode* pre1 = NULL;
        ListNode* swap1 = NULL;
        ListNode* swap2 = NULL;
        while(p){
            pre1 = p;
            swap1 = p->next;
            if (!swap1 || !swap1->next){
                break;
            }
            swap2 = swap1->next;

            swap1->next = swap2->next;
            swap2->next = swap1;
            pre1->next = swap2;

            p = swap1;
        }
        return l->next;
    }
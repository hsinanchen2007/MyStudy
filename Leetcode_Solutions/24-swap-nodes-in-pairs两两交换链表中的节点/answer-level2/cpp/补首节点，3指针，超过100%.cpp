ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* result = head->next;
        ListNode* virtual_head = new ListNode(0);//补节点
        virtual_head->next = head;
        ListNode* tmp = virtual_head;
        while (tmp){
            ListNode* curr1 = tmp->next;
            ListNode* curr2 = curr1->next;
            if (!curr2) break;
            ListNode* Next = curr2->next;
            tmp->next = curr2;
            curr1->next = Next;
            curr2->next = curr1;
            if (!Next) break;
            tmp = curr1;
        }
        return result;
    }
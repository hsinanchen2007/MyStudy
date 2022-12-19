    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        int i=0;
        ListNode* nextHead=head,*current,*prev,*next;
        while(nextHead!=NULL&&i<k){
            nextHead=nextHead->next;
            i++;
        }
        if(i==k){
            prev=head;
            current=head->next;
            next=current->next;
            while(next!=nextHead){
                current->next=prev;
                prev=current;
                current=next;
                next=next->next;
            }
            current->next=prev;
            head->next=reverseKGroup(nextHead,k);
            return current;
        }
        else{
            return head;
        }
    }
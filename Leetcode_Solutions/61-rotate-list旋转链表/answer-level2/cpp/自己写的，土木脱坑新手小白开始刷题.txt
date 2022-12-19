        ListNode *rear=head;
        int n=1;
        if(!head||!head->next) return head;
        while(rear->next){
            rear=rear->next;
            n++;
        }
        rear->next=head;
        for(int i=0;i<n-k%n;i++){
            head=head->next;
            rear=rear->next;
        }
        rear->next=NULL;
        return head;

ListNode *detectCycle(ListNode *head) {
        ListNode *low=head;
        ListNode *fast=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            low=low->next;
            if(low==fast)break;
        }
        if(!fast||!fast->next){
            return NULL;
        }
        else{
            ListNode *p=low->next;
            int len1=0;
            while(p!=low){
                p=p->next;
                len1++;
            }
            ListNode *q=head;
            int len2=0;
            while(q!=low){
                q=q->next;
                len2++;
            }
            p=low->next;
            q=head;
            while(len1>len2){
                p=p->next;
                len1--;
            }
            while(len2>len1){
                q=q->next;
                len2--;
            }
            while(p!=q){
                p=p->next;
                q=q->next;
            }
            return p;
        }
    }
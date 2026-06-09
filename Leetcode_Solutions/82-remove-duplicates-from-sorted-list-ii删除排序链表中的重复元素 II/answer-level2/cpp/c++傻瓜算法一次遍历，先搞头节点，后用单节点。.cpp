class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *t=head;
        ListNode*p=head;
        if(head==NULL||head->next==NULL)
            return head;
        int num;
        int flag=0;
        while(head&&(head->next)&&(head->val==head->next->val))
        {
            flag=0;
            head=head->next;
            if(head&&head->next&&head->val!=head->next->val)
            {
                flag=1;
                head=head->next;
            }
            if(head->next==NULL&&flag)
                return head;
            if(head->next==NULL&&flag==0)
                return NULL;
        //if(head->next)
            // p=head->next;
        }
        t=head;
        while(t->next!=NULL)
        {
        if((t->val)==(t->next->val))
        {
            p=head;
            while(p&&p->next&&p->next!=t)
            {
                p=p->next;
            }
            while(t&&(t->next)&&((t->val)==(t->next->val)))
            {
                t=t->next;
            }
            if(t->next!=NULL)
            {
            p->next=t->next;
            t=t->next;
            }
            else
            {
                p->next=NULL;
                return head;
            }
            
        }
        else
        {
            t=t->next;
        }
    
        }
        return head;
        }
};
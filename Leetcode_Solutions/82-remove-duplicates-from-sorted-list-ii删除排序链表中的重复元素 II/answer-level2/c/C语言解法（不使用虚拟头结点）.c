struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *prev=NULL;
    struct ListNode *cur=head;
    while(cur!=NULL&&cur->next!=NULL){
        if(cur->next->val!=cur->val){
            prev=cur;
            cur=cur->next;
        } else{
            //deletes duplicates until a new val appears or until the list ends
            //update head if its the first node
            int val2=cur->val;
            while (cur!=NULL&&cur->val==val2){
                struct ListNode *temp=cur->next;
                free(cur);
                cur=temp;
            }
            if(prev!=NULL)
                prev->next=cur;
            else
                head=cur;
        }
    }
    return head;
}
int getDecimalValue(struct ListNode* head){
    int sum=0;
    while(head!=NULL){
        sum=sum*2+ head->val;
        head=head->next;
    }  
    return sum;  
}
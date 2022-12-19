```c
int getDecimalValue(struct ListNode* head){
    int result=0;
    while(head!=0){
        result=result*2+head->val;
        head=head->next;
    }
    return result;
}
```
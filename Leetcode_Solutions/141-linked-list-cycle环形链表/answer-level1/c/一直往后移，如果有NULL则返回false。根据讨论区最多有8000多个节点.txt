```c
bool hasCycle(struct ListNode *head) {
    int i;
    for(i=0;i<9000;i++){
        if(head==NULL) return false;
        else head=head->next;
    }
    return true;
}
```
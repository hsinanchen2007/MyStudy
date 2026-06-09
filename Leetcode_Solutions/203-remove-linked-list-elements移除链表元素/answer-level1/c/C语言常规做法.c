第一步是处理节点位于开头的情况，后续较为常规，不再赘述。
```c
struct ListNode* removeElements(struct ListNode* head, int val){
    while(head!=0&&head->val==val) head=head->next;
    struct ListNode* tmp=head;
    while(tmp!=0)
        if(tmp->next!=0&&tmp->next->val==val) tmp->next=tmp->next->next;
        else tmp=tmp->next;
    return head;
}
```
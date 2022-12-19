```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* p;
    struct ListNode* q;
    p=head;
    q=head;

    if(n==1&&head->next==NULL) return NULL;  //只有一个节点并且删除它
    else{
        while((n--)&&p!=NULL) p=p->next;
        if(!p) head=head->next;           //要删除的是第一个节点
        else{                             //其他情况
            p=p->next;
            while(p!=NULL){
                p=p->next;
                q=q->next;
            }
            q->next=q->next->next;
        }
    } 
    return head;
}
```

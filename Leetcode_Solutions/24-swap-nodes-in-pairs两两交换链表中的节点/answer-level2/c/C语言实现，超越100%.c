
```
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* before=(struct ListNode*)malloc(sizeof(struct ListNode));
    before->next=head;
    struct ListNode* p=before;
    //注意这里需要判断p->next是否为NULL，不然p->next->next!=NULL可能会报错
    while(p->next!=NULL&&p->next->next!=NULL){
        //交换两个工作指针后的两个指针
        struct ListNode* temp=p->next;
        p->next=p->next->next;
        temp->next=p->next->next;
        p->next->next=temp;
        
        //进行下一次交换操作
        p=temp;
    }
    return before->next;
}
```

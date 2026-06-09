```
struct ListNode * moveone(struct ListNode *head){
    struct ListNode *pre=head;
    struct ListNode *cur=head;
    while(cur->next){
        pre=cur;
        cur=cur->next;
    }
    pre->next=NULL;//倒数第二个节点变成最后一个
    cur->next=head;//最后一个节点变成头节点
    return cur;
}
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL||head->next==NULL)return head;
    struct ListNode*p=head;
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    k=k%len;
    while(k--){
        struct ListNode* tmp=moveone(head);//移动一次
        head=tmp;   //移动后都要跟换链表头部的嘛
    }
    return head;
}
```

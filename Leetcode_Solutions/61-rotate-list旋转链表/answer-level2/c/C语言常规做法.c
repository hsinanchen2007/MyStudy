把链表首尾相连，再在正确的位置断开即可。
```c
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==0) return 0;
    short length=1;
    struct ListNode* tmp=head;
    while(tmp->next!=0){
        tmp=tmp->next;
        length++;
    }
    tmp->next=head;
    k=length-k%length;
    while(k--) tmp=tmp->next;
    head=tmp->next;
    tmp->next=0;
    return head;
}
```
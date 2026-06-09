- 方法一
双指针法
```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode*slow_p=head,*p=head;
    while(n--) p=p->next;
    if(p==0) return head->next;
    p=p->next;
    while(p!=0){
        slow_p=slow_p->next;
        p=p->next;
    }
    slow_p->next=slow_p->next->next;
    return head;
}
```
- 方法二
常规做法
```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    short len=0;
    struct ListNode* tmp;
    tmp=head;
    while(tmp!=0){
        len++;
        tmp=tmp->next;
    }
    tmp=head;
    len=len-n-1;
    if(len==-1) return head->next;
    while(len--) tmp=tmp->next;
    tmp->next=tmp->next->next;
    return head;
}
```
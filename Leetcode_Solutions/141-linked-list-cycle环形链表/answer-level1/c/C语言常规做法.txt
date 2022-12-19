- 方法一
利用双指针。
```c
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast_p=head,*slow_p=head;
    while(fast_p!=0&&fast_p->next!=0){
        slow_p=slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p==fast_p) return 1;
    }
    return 0;
}
```
- 方法二
此方法较笨。
```c
bool hasCycle(struct ListNode *head) {
    struct ListNode *Addr[10000]={0};
    short i=0,j;
    while(head!=0){
        for(j=0;j<10000;j++)
            if(head==Addr[j]) return 1;
        Addr[i]=head;
        head=head->next;
        i++;
    }
    return 0;
}
```
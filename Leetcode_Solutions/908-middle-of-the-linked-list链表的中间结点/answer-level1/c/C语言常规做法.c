- 方法一
双指针法
```c
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow_p=head,*fast_p=head;
    while(fast_p!=0&&fast_p->next!=0){
        fast_p=fast_p->next->next;
        slow_p=slow_p->next;
    }
    return slow_p;
}
```
- 方法二
常规做法
```c
struct ListNode* middleNode(struct ListNode* head){
    short length=0;
    struct ListNode *tmp;
    tmp=head;
    while(tmp!=0){
        length++;
        tmp=tmp->next;
    }
    length=length/2;
    while(length--) head=head->next;
    return head;
}
```
```
struct ListNode* reverseList(struct ListNode* head){
    //将尾结点指向的NULL放在最左边，R指针放在L右边一个节点，用tmp记录R右边的一个节点
    //以便R和L指针右移。完成后L成为链表的头指针，返回L。
    struct ListNode * L = NULL,  *R = head, * tmp;
    
    while(R)    //无论传入的是否是空链表，都可正确判断
    {
        tmp = R->next;
        R->next = L;
        L = R;
        R = tmp;
    }
    
    return L;
}
```

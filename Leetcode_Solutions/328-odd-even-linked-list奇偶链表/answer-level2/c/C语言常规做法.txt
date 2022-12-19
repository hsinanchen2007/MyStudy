先将链表分为奇链表和偶链表，再将奇链表尾部与偶链表头部连接。
```c
struct ListNode* oddEvenList(struct ListNode* head){
    if(head==0||head->next==0) return head;
    struct ListNode* odd_p=head,* even_p=head->next,*even_head=even_p;
    while(even_p!=0&&even_p->next!=0){
        odd_p->next=even_p->next;
        odd_p=odd_p->next;
        even_p->next=odd_p->next;
        even_p=even_p->next;
    }
    odd_p->next=even_head;
    return head;
}
```
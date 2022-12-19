先把要反转的部分提出来，反转完成再接回去。
```c
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode header;
    header.next=head;
    struct ListNode* traverse=&header, *tmp, *sign;
    //找到开始反转的节点的前一个节点。
    while(n--,--m) traverse=traverse->next;  
    sign=traverse;
    //将原链表分为两部分，sec作为新链表开头，sign为新链表头节点原位置的前一个结点。
    while(1+n--) traverse=traverse->next;
    head=sign->next;
    sign->next=traverse->next;
    traverse->next=0;
    //反转新链表。
    traverse=head;
    while(traverse&&traverse->next){
        tmp=traverse->next;
        traverse->next=tmp->next;
        tmp->next=head;
        head=tmp;
    }
    //将新链表接回去。
    traverse->next=sign->next;
    sign->next=head;
    return header.next;
}
```
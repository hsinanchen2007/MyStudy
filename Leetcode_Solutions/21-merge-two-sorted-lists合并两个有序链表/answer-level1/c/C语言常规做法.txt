将l2的节点按val的大小一个一个插入l1即可。为了处理特殊情况，可以创建一个头节点。
```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* tmp;
    struct ListNode header;
    header.next=l1;
    l1=&header;
    while(l2!=0){
        while(l1->next!=0&&l1->next->val<l2->val) l1=l1->next;
        tmp=l2;
        l2=l2->next;
        tmp->next=l1->next;
        l1->next=tmp;
    }
    return header.next;
}
```
- 方法一
遍历链表，遇到val值大于等于x的节点就将其移至链表尾部。
```c
struct ListNode* partition(struct ListNode* head, int x){
    if(head==0) return head;
    struct ListNode header;
    header.next=head;
    struct ListNode* tail=head;
    short length=1;
    while(tail->next!=0){
        tail=tail->next;
        length++;
    }
    head=&header;
    while(length--){
        if(head->next->val>=x){
            tail->next=head->next;
            head->next=head->next->next;
            tail->next->next=0;
            tail=tail->next;
        }
        else head=head->next;
    }
    return header.next;
}
```
- 方法二
将val值小于x的节点从原链表提出，构成一个新链表，再将原链表接到新链表结尾。
```c
struct ListNode* partition(struct ListNode* head, int x){
    if(head==0) return 0;
    struct ListNode header;
    header.next=head;
    struct ListNode* tmp=&header,* res=head;
    //找到第一个val值小于x的节点并提出。
    while(tmp&&tmp->next){
        if(tmp->next->val<x){
            res=tmp->next;
            break;
        }
        tmp=tmp->next;
    }
    if(tmp->next) tmp->next=tmp->next->next;
    //将原链表中后续val值小于x的节点提出到新建链表。
    tmp=&header;
    head=res;
    while(tmp&&tmp->next){
        if(tmp->next->val<x){
            head->next=tmp->next;
            tmp->next=tmp->next->next;
            head=head->next;
        }
        else tmp=tmp->next;
    }
    //连接两链表。
    if(header.next!=head) head->next=header.next;
    return res;
}
```
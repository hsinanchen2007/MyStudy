代码如下：
```
struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }//考虑到特殊情况，链表为空便不需要反转
    struct ListNode *p=head;//先将头结点记为p
    struct ListNode *q=head->next;//将首元结点记为q
    struct ListNode *r=NULL;//指针r后面起的作用是记录剩余链表部分，防止找不到
    head->next=NULL;//原先的头指针是生成的反转链表的尾指针，则其next需要指向NULL
    while(q){//只要未到结点尾部，持续对链表中的每一个元素进行反转
        r=q->next;//记录暂时未参与反转操作的剩余部分的链表
        q->next=p;//q的指针域指向q的前驱结点p
        p=q;
        q=r;//将p,q向后移动，进行下一个元素的反转
    }
    head=p; //退出循环后，已反转成功，此时p为原先链表的尾结点，又为新链表的头结点
            //为返回值统一，可将其赋值给head，也可忽略此步，则下面return p;
    return head;//返回反转形成的新链表的头结点
}
```

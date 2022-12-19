所有的关键点都写在代码注释上了，大家可以自取。

代码部分
```
struct ListNode* insertionSortList(struct ListNode* head){
    //注明：第一个节点已经排好序了我们从第二个节点开始排序，我们先构造一个链表。
    if(head==NULL||head->next==NULL)
        return head;
    //这里应该构造一个虚拟头结点
    struct ListNode* s=(struct ListNode*)malloc(sizeof(struct ListNode));
    s->next=head;
    head=s;
    //p指针——遍历指针，r指针（保存p后继元素）,pre指针，找到插入位置。
    //这里最重要的是先隔离一个元素，把它和后面断开
    struct ListNode *p=head->next,*pre;
    struct ListNode *r=p->next;   //r是p后面的指针，保证不断链
    p->next=NULL;              //首先构造一个单独的单链表
    p=r;                       //将p的值赋值为r，从链表中第二个元素开始遍历
    while(p!=NULL)
    {
        r=p->next;             //保存p后继元素的指针
        pre=head;
        while(pre->next!=NULL&&pre->next->val<p->val)  //找到该点应该被插入的前驱节点
            pre=pre->next;
        p->next=pre->next;     //这两部是将p插入到pre和pre->next之间
        pre->next=p;
        p=r;                   //r指针起到保存作用还原p遍历的位置。
    }
    return head->next;
}




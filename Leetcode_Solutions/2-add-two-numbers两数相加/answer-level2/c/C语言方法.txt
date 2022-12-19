### 解题思路
代码核心为以下几点：
1、对于不同长度的l1和l2，统一化处理
2、利用了加法有进位的特点，使用了old_one和new_one，其中old_one表示接收到的进位，而new_one表示产生的进位
3、分别讨论了最后产生进位情况
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL&&l2==NULL) return NULL;
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    struct ListNode *p1=l1,*p2=l2,*temp,*head=l1;//head指针是为了最后输出时方便用的
    int len1=0,len2=0,old_one=0,new_one;//new_one表示进位，old_one表示接收到的进位
    while(p1)
    {
        len1++;
        p1=p1->next;
    }
    while(p2)
    {
        len2++;
        p2=p2->next;
    }
    p1=l1;//指针复位
    p2=l2;//指针复位
    if(len2>len1)//因为输入的两个链表长短可能不一，所以我们把它统一化
    {
        temp=p1;
        p1=p2;
        p2=temp;
        head=l2;
    }
    while(p1&&p2)
    {  
        if(p1->val+p2->val+old_one>=10) new_one=1;
        else new_one=0;
        p1->val=(p1->val+p2->val+old_one)%10;
        old_one=new_one;
        p1=p1->next;
        p2=p2->next;
    }
    while(p1)//处理一个链表结束了，另一个链表仍然有元素的情况
    {
        if(p1->val+old_one>=10) new_one=1;
        else new_one=0;
        p1->val=(p1->val+old_one)%10;
        old_one=new_one;
        p1=p1->next;
    }
    if(old_one==1)//处理两个链表都结束了，但是最后一次计算和的时候还是有进位的情况
    {
        struct ListNode *r=head,*q;
        q=(struct ListNode*)malloc(sizeof(struct ListNode));
        q->val=1;
        q->next=NULL;
        while(r->next) r=r->next;
        r->next=q;
        return head;
    }
    return head;
}
```
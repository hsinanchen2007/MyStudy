### 解题思路
方法一：
假设原链表：1 2 3 4 5 6 7 8
1.首先将一个链表分成两个
1 2 3 4  
5 6 7 8
2.将第二个链表翻转
1 2 3 4 
8 7 6 5
3.合并两个链表
1 8 2 7 3 6 4 5
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//暴力解决
int getlength(struct ListNode* head)
{
    int length=0;
    while(head)
    {
        length++;
        head=head->next;
    }
    return length;
}
struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *q,*r;
    struct ListNode *new_head=(struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->next=NULL;
    while(head->next)
    {
        q=head->next;
        r=q->next;
        head->next=r;
        q->next=new_head->next;
        new_head->next=q;
    }
    return new_head->next;
}
void reorderList(struct ListNode* head){
    if(!head||!head->next)
    return head;
    int length=getlength(head)+1;
    length/=2;
    
    struct ListNode *p=head;
    length--;
    while(length)
    {
        length--;
        p=p->next;
    }
    struct ListNode *new_head=(struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->next=reverse(p);
    p->next=NULL;

    p=head;
    struct ListNode *q,*r;
    while(new_head->next)
    {
        q=new_head->next;
        r=q->next;
        new_head->next=r;
        q->next=p->next;
        p->next=q;
        p=q;
        p=p->next;
    }
    return head;
}
```
方法二：
如果我们能够把每个头节点所堆成的尾节点进行返回，这样从中间往外，中间的链表都是排序号的，然后将收到的尾节点插入到头结点之后即可。

这里需要用到快慢指针，快指针走两步，慢指针走一步，然后分别考虑奇数和偶数的情况
奇数：1 2 3 4 5
慢指针指向3，快指针越界，那么我们只需要把4返回，3的末尾指向空。

偶数：1 2 3 4 5 6
慢指针指向3，快指针指向6，我们需要用3->4,因为恰好4是3所对称的尾节点，我们需要返回5.
```c
//递归解决
struct ListNode *sortList(struct ListNode *low,struct ListNode *fast)
{
    //处理边界条件
    if(!fast)//奇数
    {
        struct ListNode* q=low->next;
        low->next=NULL;
        return q;
    }
    if(!fast->next)//偶数
    {
        struct ListNode* p=low->next;
        struct ListNode* q=p->next;
        p->next=NULL;
        return q;
    }
    struct ListNode *tail=sortList(low->next,fast->next->next);
    struct ListNode *target=tail->next;
    tail->next=low->next;//尾插法
    low->next=tail;
    return target;
}
void reorderList(struct ListNode* head){
    if(!head||!head->next)
    return head;
    sortList(head,head->next);
    return head;
}
```

1. **链表拼接法:**从head链表依次遍历，把小于x的值依次用链表l1存储起来，大于或等于x的值用l2链接起来，然后链表l1的尾指针指向l2链表的头结点，即可。
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));//链表l1
    l1->next = NULL;
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));//链表l2
    r->next = NULL;
    struct ListNode *p,*pl,*p2;
    p = head;
    pl = l1;
    p2 = l2;
    while(p){
        if(p->val < x){
            pl->next = p;
            pl = p1->next;
            p = p->next;
            pl->next = NULL;
        }
        else{
            p2->next = p;
            p2 = p2->next;
            p = p->next;
            p2->next = NULL;
        }
    }
    pl->next = l2->next;
    return l1->next;
}
```

 
2. **原链表排序法：**取其链表数据域中第一个>=x的指针作为断点，然后把断点后的指针一次遍历按顺序依次进行插入，这种方法时间复杂度为o(n)运行速度快,但占用内存较多。
```
struct ListNode* partition(struct ListNode* head, int x){

if (NULL == head)//边界条件
{
    return NULL;
}
struct ListNode* L,*p,*q,*tag;
L=(struct ListNode*)malloc(sizeof(struct ListNode));
L->next=head;
q=L;
while(q->next!=NULL)//找寻第一个标志位
{
    tag=q;
    q=q->next;
    if(q->val>=x)
      break;
}
if(q->next==NULL)//边界条件，若前面均大于等于x，则返回head;
  return head;

/***
把位于标志位tag->next后面的值进行遍历，凡是小于x的值顺序放入tag->next的前面。q是断点
***/
struct ListNode*pre,*rear;
rear=q->next;
pre=q;
while(rear)
{
    if(rear->val>=x)
    {
        pre=pre->next;
        rear=rear->next;
    }
    //rear为小于x的值，即把q插入tag->next的后面
    else
    {
        pre->next=rear->next;//首先删除rear结点
        rear->next=q;//添加结点操作
        tag->next=rear;
        tag=tag->next;//更新，断点不变
        rear=pre->next;//更新rear结点
    }
}
return L->next;
}

```
//一个新链表一个原链表法
```

struct ListNode* partition(struct ListNode* head, int x){

if(!head||!(head->next)) return head;
struct ListNode*L1=(struct ListNode*)malloc(sizeof(struct ListNode));
L1->next=NULL;
struct ListNode*L=(struct ListNode*)malloc(sizeof(struct ListNode));
L->next=head;
struct ListNode*p,*post,*pre1=L1,*phead=L;

/**
将小于x的结点从原链表分离出来
**/
p=head;
while(p)
{
    while(p)
    {
    post=p->next;
    if(p->val<x)
    break;
    p=post;
    phead=phead->next;
    }

    struct ListNode *cur=p;
    if(p)
    {
    p=p->next;
    phead->next=p;
    }
/**
新链表l1插值
**/
    if(cur)
    {
    cur->next=pre1->next;
    pre1->next=cur;
    pre1=pre1->next;
    }

}
pre1->next=L->next;
return L1->next;
}
```

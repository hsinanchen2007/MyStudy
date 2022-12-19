### 解题思路
根据归并排序的特点，主要分为三步：
1.把每个链表分割成两个子连续，直到链表的长度为1或者2
2.对每个子链表进行排序
3.再把所有的链表合并起来

1.这里的分割，我采用的快慢指针的分割方式：快指针走两步，慢指针只走一步
奇数和偶数的两种情况均可以分割。

2.排序，我们这里由于采用的空间复杂度为O(1)
那么我们只考虑把第二个链表插入到第一个链表。
插入元素主要包含了两个部分，分割和插入，他们都需要保留当前需要分割元素和待插入位置的前一个元素。
插入分割原则：为了保证插入能够有序，当前元素小于等于待插入元素的值，后一个元素大于待插入元素的值。否则，该位置舍弃，继续前进。

这里需要考虑一种特殊情况，第一个链表再也找不到比第二个链表的大的元素，则直接把第二个链表全部插入。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *merge(struct ListNode *p,struct ListNode *q)
{
    struct ListNode *headp=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *headq=(struct ListNode*)malloc(sizeof(struct ListNode));
    if(p->val>q->val)//确保起始元素小的为第一个链表
    {
        struct ListNode *t=p;
        p=q;q=t;
    }
    headp->next=p;headq->next=q;
    struct ListNode *prep=headp,*preq=headq,*t;
    while(prep->next&&preq->next)
    {
        if(prep->next->val<preq->next->val)
        {
            prep=prep->next;
        }
        else
        {//把q中元素插入到p中
            //分离q
            t=preq->next;
            preq->next=t->next;
            t->next=prep->next;
            prep->next=t;
            prep=t;
        }
    }
    if(preq->next)
        {
            prep->next=preq->next;
        }
    p=headp;
    return headp->next;
}
struct ListNode* sortList(struct ListNode* head){
    if(!head||!head->next)
    return head;
    struct ListNode *p=head;
    struct ListNode *q=head->next;
    while(q&&q->next)
    {
        p=p->next;
        q=q->next->next;
    }
    q=p->next;
    p->next=NULL;
    return merge(sortList(head),sortList(q));
}


```
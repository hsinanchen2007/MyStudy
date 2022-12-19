### 解题思路
根据翻转链表|对整个链表进行翻转到||，对其中某一部分进行翻转。那么我寻思着肯定是能够对很大程度上引用|的方法。

对于|我直接进行尾插法对链表进行翻转，那么我们就只需要用p指向头，q指向尾即可。然后直接利用尾插法进行翻转。

这里我自认为自己比较灵活，不是这一道题，是leetcode常常有时候给头结点有时候不给头结点，这里没有给。头结点的优点主要就是对于链表中的任何一点结点都是进行统一化操作，这个优点很棒。既然这道题没给，那我何不尝试自建头结点呢？

然后我们只需保存p的前驱检点，待p至q这段链表翻转后我们再让前驱指向q不久可以了吗？

但是这里有一点是需要我们精细考虑的。如果m！=1，那么head这个节点是不是没有参与到翻转，它仍然是首节点，如果m==1，head就直接到最后一个节点，你说是不是？

m==1的时候，我们的头结点是没有改变的，m！=1的时候，头结点就是前驱节点。

我讲的非常详细了，只是没有配图，不懂的欢饮留言~一定细心解答！

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode *p=head,*q=head;
    struct ListNode *t1,*t2,*r;
    t1=(struct ListNode*)malloc(sizeof(struct ListNode));
    t1->next=head;//自建头结点，也是头结点
    int i=1;
    while(i<m)//定位到开始改变的首节点
    {
        t1=t1->next;
        i++;
        p=p->next;
    }
    q=p;
    while(i<n)//结束的尾节点
    {
        i++;
        q=q->next;
    }
    while(p!=q)
    {
        r=p->next;
        p->next=q->next;
        q->next=p;
        p=r;

    }
    t1->next=q;
    if(m==1)
    head=t1->next;
    return head;
}
```
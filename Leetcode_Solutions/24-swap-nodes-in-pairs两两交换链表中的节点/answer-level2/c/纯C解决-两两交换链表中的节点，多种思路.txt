### 解题思路
在这里总结一下链表题目的做法总结，基本方法有两种，一般的链表题目都是可以用这两种方法解决
```
1.直接法

2.递归法
```
这两种方法的特点如下：
```
1.直接法就是可以直接从头开始遍历操作，这种思路很简单

2.递归法，就是对于我们平时解决那种需要倒序遍历操作的题目
```


### 代码

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//直接法
struct ListNode* swapPairs(struct ListNode* head){
    if(!head||!head->next)return head;
    struct ListNode *p=head,*q=head->next,*r,*pre;
    head=q;
    r=q->next;
    p->next=q->next;
    q->next=p;
    pre=p;
    p=r;
    if(p)
    q=p->next;
    while(p&&q)
    {
        pre->next=q;
        r=q->next;
        p->next=q->next;
        q->next=p;
        pre=p;
        p=r;
        if(p)
        q=p->next;
    }
    return head;
}
```

```c
//递归
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *Reverse(struct ListNode *low,struct ListNode *fast)
{
    if(!fast)return low;
    if(!fast->next)
    {
        low->next=fast->next;
        fast->next=low;
        return fast;
    }
    struct ListNode *tail=Reverse(fast->next,fast->next->next);
    low->next=tail;
    fast->next=low;
    return fast;
}
struct ListNode* swapPairs(struct ListNode* head){
    if(!head||!head->next)return head;
    return Reverse(head,head->next);
}


```
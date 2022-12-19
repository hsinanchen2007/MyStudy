### 解题思路
这道题我觉得没啥难点，递归和直接都很容易，给hard我觉得评价过了。

不太懂的欢迎留言，一定细心解答~

### 代码

```c
//直接法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *p=head,*q=head;
    struct ListNode *r,*pre,*t;
    pre=(struct ListNode*)malloc(sizeof(struct ListNode));
    pre->next=p;
    int i,count=0;

    while(p)
    {
        t=p;
        count++;
        i=1;
        while(i<k&&q)//到尾部
        {
            q=q->next;
            i++;
        }
        if(!q)
        return head;
        while(p!=q)
        {
            r=p->next;
            p->next=q->next;
            q->next=p;
            p=r;
        }
        if(count==1)//第一次翻转
        head=q;
        pre->next=q;//连接
        pre=t;//后移
        p=t->next;
        q=p;
    }
    return head;
}
```
```
//递归法
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *p=head,*q=head;//头尾
    int i=1;
    while(i<k&&q)
    {
        q=q->next;
        i++;
    }
    if(q)
    {

        struct ListNode *r,*t;
        t=p;
        while(p!=q)//尾插法
        {
            r=p->next;
            p->next=q->next;
            q->next=p;
            p=r;
        }
        t->next=reverseKGroup(t->next,k);
        return q;
    }
    return head;
}
```
```c
//递归2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverse(struct ListNode *head,int k)
{
    if(!head)return head;
    printf("%d ",head->val);
    int count=k;
    struct ListNode *new_head;
    new_head=head;

    //找到新的头节点
    while(count>1&&new_head)
    {
        count--;
        new_head=new_head->next;
    }

    if(!new_head)return head;//不需要逆转
    struct ListNode *tail=reverse(new_head->next,k);//找到下一个结点的头节点
    //逆转链表
    new_head=head;count=k;
    struct ListNode *pre=head,*r=head->next;
    while(count>1)
    {
        pre=new_head;
        new_head=r;
        r=new_head->next;
        new_head->next=pre;
        count--;
    }
    head->next=tail;
    return new_head;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    return reverse(head,k);
}
```

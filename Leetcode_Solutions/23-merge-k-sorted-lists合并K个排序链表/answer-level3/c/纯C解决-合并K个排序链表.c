### 解题思路
这道题的思路我认为还是很简单的，就是对每两个链表进行合并，依次合并直到结束。然后我在这里采用了不加头节点和加头节点的方式来做这道题，大家也可以稍微对比一下，很多人可能会毫不犹豫的觉得不加头节点肯定没有加了头节点的方便。
答案确实如此，我就是想锻炼一下自己的考虑问题是否周全的能力。不喜勿喷~
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//不加头节点
struct ListNode* Merge(struct ListNode *l1,struct ListNode *l2)
{
    if(!l1)return l2;
    if(!l2)return l1;
    struct ListNode *p1=l1,*p2=l2,*head;
    if(p1->val>p2->val)//小的做表头
    {
        p2=l1;p1=l2;
    }   
    head=p1;
    while(p1->next&&p2->next)//把p2插入到p1链表
    {
        if(p1->next->val>p2->next->val)//p2的插入条件
        {
            struct ListNode *q=p2->next;
            p2->next=q->next;
            q->next=p1->next;
            p1->next=q;
        }
        p1=p1->next;
    }
    //三种可能结束条件
    if(p2->next&&!p1->next)
        p1->next=p2->next;
    if(p2==l1)//插入到l2中
    {
        while(l2->next&&l2->next->val<=p2->val)
            l2=l2->next;
        p2->next=l2->next;
        l2->next=p2;
        return head;
    }
    //插入到l1
    while(l1->next&&l1->next->val<=p2->val)
    l1=l1->next;
    p2->next=l1->next;
    l1->next=p2;
    return head;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0)return NULL;
    if(listsSize==1)return lists[0];
    struct ListNode* head=Merge(lists[0],lists[1]);
    int i;
    for(i=2;i<listsSize;i++)
    head=Merge(head,lists[i]);
    return head;
}
```
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//加头节点
struct ListNode* Merge(struct ListNode *l1,struct ListNode *l2)
{
    if(!l1)return l2;
    if(!l2)return l1;
    struct ListNode *p1=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2=(struct ListNode *)malloc(sizeof(struct ListNode));
    p1->next=l1;p2->next=l2;
    if(p1->next->val>p2->next->val)//小的做表头
    {
        p2->next=l1;p1->next=l2;
    }   
    struct ListNode *head=p1->next;
    while(p1->next&&p2->next)//把p2插入到p1链表
    {
        if(p1->next->val>p2->next->val)//p2的插入条件
        {
            struct ListNode *q=p2->next;
            p2->next=q->next;
            q->next=p1->next;
            p1->next=q;
        }
        p1=p1->next;
    }
    //可能结束条件
    if(p2->next&&!p1->next)
        p1->next=p2->next;
    return head;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0)return NULL;
    if(listsSize==1)return lists[0];
    struct ListNode* head=Merge(lists[0],lists[1]);
    int i;
    for(i=2;i<listsSize;i++)
    head=Merge(head,lists[i]);
    return head;
}
```

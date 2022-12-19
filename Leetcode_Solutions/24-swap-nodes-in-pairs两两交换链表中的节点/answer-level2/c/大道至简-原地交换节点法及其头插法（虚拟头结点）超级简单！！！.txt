执行用时 :
0 ms
, 在所有 c 提交中击败了
100.00%
的用户
内存消耗 :
7 MB
, 在所有 c 提交中击败了
95.77%
的用户
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){

if(!head||!(head->next))  return head;//边界条件

struct ListNode*L,*p,*q;
L=(struct ListNode*)malloc(sizeof(struct ListNode));//头结点
L->next=head;
p=head;
q=L;
/***
两两交换相邻的结点，若为奇数个只交换前面偶数个
****/
while(p->next)
{
    q->next=p->next;//下面四步为结点交换顺序
    q=q->next;
    p->next=q->next;
    q->next=p; 
    if(p->next)//交换结点后再判断p下一个结点是有为空
    {
    p=p->next;
    q=q->next;
    }
    else
    break;
} 
return L->next;
}
```
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){

if(!head||!(head->next))  return head;

struct ListNode *L,*pre,*p,*post,*rear;
L=(struct ListNode*)malloc(sizeof(struct ListNode));
L->next=NULL;
pre=L;
p=post=head;

while(post->next)
{
    int i=0;
    while(post&&i<2)
    {
        
        post=post->next;
        p->next=pre->next;
        pre->next=p;
        if(i==0)
          rear=p;
        p=post;
        i++;
    }
    pre=rear;
    i=0;
    if(!p)
      break;
    else if(!(p->next))
    {
        rear->next=p;
    }
}
pre=L->next;
free(L);
head=pre;
return head;
}
```
//递归解法
```

struct ListNode* swapPairs(struct ListNode* head){

if(head==NULL||head->next==NULL)  return head;

struct ListNode *p=head->next;
head->next=swapPairs(p->next);
p->next=head;

return p;
}

```

![image.png](https://pic.leetcode-cn.com/212cfc51e00205c3f1d1706ad847043187476b2ecebe5a11f57484e42c608284-image.png)

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head){    

if(!head)  return NULL;
struct ListNode*L=(struct ListNode*)malloc(sizeof(struct ListNode));
L->next=head;
struct ListNode*p=L,*post;
while(p)
{
    post=p->next;
    int sum=0;
    while(post)
    {
        sum+=post->val;
        if(sum==0)
        break;
        post=post->next;
    }
    if(post)
    p->next=post->next;
    else
    p=p->next;
}
return L->next;
}
```

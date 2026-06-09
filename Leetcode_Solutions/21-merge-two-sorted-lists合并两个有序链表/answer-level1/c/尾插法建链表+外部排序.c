### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
struct ListNode *l3;
struct ListNode *last;
l3=(struct ListNode *)malloc(sizeof(struct ListNode));
l3->next = NULL;
last=l3;
while(l1&&l2)
{if(l1->val>l2->val)
    {struct ListNode *p;
    p=(struct ListNode *)malloc(sizeof(struct ListNode));
    p->val=l2->val;
    p->next=last->next;
    last->next=p;
    last=p;
    l2=l2->next;
    }
    else
    {struct ListNode *q;
    q=(struct ListNode *)malloc(sizeof(struct ListNode));
    q->val=l1->val;
    q->next=last->next;
    last->next=q;
    last=q;
    l1=l1->next;
    }
    }
while(l1)
{struct ListNode *q;
    q=(struct ListNode *)malloc(sizeof(struct ListNode));
    q->val=l1->val;
    q->next=last->next;
    last->next=q;
    last=q;
    l1=l1->next;}
while(l2)
{struct ListNode *p;
    p=(struct ListNode *)malloc(sizeof(struct ListNode));
    p->val=l2->val;
    p->next=last->next;
    last->next=p;
    last=p;
    l2=l2->next;}
    return l3->next;
}
```
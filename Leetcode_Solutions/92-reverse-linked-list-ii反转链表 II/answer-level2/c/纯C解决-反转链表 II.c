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


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(!head||!head->next||m==n)return head;
    struct ListNode *new_head=(struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->next=head;
    struct ListNode *pre=new_head;
    while(m>1)
    {
        pre=pre->next;
        n--;m--;
    }
    struct ListNode *p,*r,*tail;
    p=pre->next;
    tail=p;
    pre->next=NULL;
    while(n>0)
    {
        //printf("%d ",p->val);
        n--;
        r=p->next;
        p->next=pre->next;
        pre->next=p;
        p=r;
    }
    tail->next=p;
    return new_head->next;
}
```
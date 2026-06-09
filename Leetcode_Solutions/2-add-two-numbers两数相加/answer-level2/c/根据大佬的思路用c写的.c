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


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1=NULL,*p=NULL,*head=NULL;
    p1=(struct ListNode*)malloc(sizeof(struct ListNode));
    p=p1;
    int t=0,n=0;
    while(l1!=NULL || l2!=NULL || t!=0)
    {
        if(l1 != NULL)
        {
            t += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            t += l2->val;
            l2 = l2->next;
        }
        p1=(struct ListNode*)malloc(sizeof(struct ListNode));
        p1->val=t%10;
        n=n+1;
        if(n==1) head=p1;
        else p->next = p1;
        p=p1;
        t=t/10;
    }
    p->next=NULL;
    return head;
    
}
```
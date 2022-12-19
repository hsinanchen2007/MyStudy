### 解题思路
基本操作

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
    struct ListNode * head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->next=0;
    struct ListNode *iter=head;
    while(l1!=0&&l2!=0)
    {
        struct ListNode *p;
        if(l1->val<=l2->val)
        {
            p=l1;
            l1=l1->next;
        }
        else
        {
            p=l2;
            l2=l2->next;

        }
        p->next=iter->next;
        iter->next=p;
        iter=iter->next;
    }
    iter->next=l1==0?l2:l1;

    iter=head->next;
    free(head);
    return iter;
}
```
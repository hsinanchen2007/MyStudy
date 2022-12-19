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
    
    struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = 0;
    ret->next = NULL;
    struct ListNode *p = ret;
    int flag = 0;

    while(l1 != NULL && l2 != NULL)
    {
        struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val =0;
        tmp->next = NULL;

        if(p->next == NULL)
        {
            p->next = tmp;
            p = p->next;
            p->val = (flag + l1->val + l2->val) % 10;
            flag = (flag + l1->val + l2->val) / 10;
        }
        l1 = l1->next;
        l2 = l2->next; 
    }

    struct ListNode *q = NULL;
    if(l1 != NULL)
        q = l1;
    else if(l2 != NULL)
        q = l2;
            
    while(q != NULL)
    {
        struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val =0;
        tmp->next = NULL;
        if(p->next == NULL)
        {
            p->next = tmp;
            p = p->next;
            p->val = (flag + q->val) % 10;
            flag = (flag + q->val) / 10;
        }
        q = q->next;    
    }   

    if(flag == 1)
    {
        struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = flag;
        tmp->next = NULL;
        p->next = tmp;
    }
    
    return ret->next;
}
```
### 解题思路
       -->[r]-->[p]-->[q]-->
       tmp = q->next;

        r->next = q;
        q->next = p;
        p->next = tmp;

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode * first = (struct ListNode *)malloc(sizeof(struct ListNode));
    first->next = head;
    struct ListNode *r = NULL, *p = NULL, *q = NULL;
    r = first; p = r->next;
    if(p != NULL) q = p->next;
    while(r && p && q){
        struct ListNode * tmp = NULL;
        tmp = q->next;

        r->next = q;
        q->next = p;
        p->next = tmp;

        r = p;
        if(r != NULL) p = r->next;
        if(p != NULL) q = p->next;
    }

    return first->next;
}
```

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* p = head;
    struct ListNode* q = head->next;
    struct ListNode* n;
    int order = 0;
    while(q!=NULL)
    {
        if(p->val == q->val)
        {
            struct ListNode* m = q;
            q = q->next;
            p->next = q;
            free(m);
            order = 1;
            continue;
        }
        if(order == 1)
        {
            order =0;
            if(p == head)
            {
                head = q;
            }
            else
            {
                n->next = q;
            }
            free(p);
            p = q;
            q = q->next;
            continue;
        }
        n = p;
        p = p->next;
        q = q->next;
    }
    if(order == 1)
    {
        if(p == head)
        {
            free(p);
            return NULL;
        }
        else
        {
            n->next = q;
            free(p);
        }
    }
    return head;
}
```

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head == NULL)
        return head;
    struct ListNode* p =head ->next;
    struct ListNode* q = head;
    while(1)
    {
        if(head->val == val)
        {
            if(p!=NULL)
            {
                free(head);
                head = p;
                p = p->next;
                q = head;
                continue;
            }
            else
            {
                free(head);
                return NULL;
            }
        }
        if(p == NULL)
        {
            break;
        }
        else
        {
            if(p->val == val)
            {
                q ->next = p ->next;
                free(p);
                p = q->next;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
    }
    return head;
}
```
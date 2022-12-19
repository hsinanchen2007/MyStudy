### 解题思路

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
    struct ListNode *p = head;
    struct ListNode *phead = head;
    struct ListNode *pre = head;
    while (p != NULL)
    {
        if (p->val == val)
        {
            if (pre != p) 
            {
                pre->next = p->next;
                free(p);
                p = pre->next;
            }
            else 
            {
                pre = p->next;
                free(p);
                p = pre;
                phead = p;
            }
        }
        else 
        {
            pre = p;
            p = p->next;
        }
    }
    return phead;
}
```
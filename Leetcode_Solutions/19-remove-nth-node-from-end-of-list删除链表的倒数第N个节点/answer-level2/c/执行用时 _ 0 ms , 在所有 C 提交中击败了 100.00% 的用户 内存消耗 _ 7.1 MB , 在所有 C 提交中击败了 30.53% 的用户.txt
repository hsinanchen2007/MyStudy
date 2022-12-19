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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if(head->next == NULL)return NULL;
    struct ListNode *r = head;
    while(n > 0 )
    {
        r = r->next;
        n--;
    }
    if(r == NULL)
    {
        head = head->next;
        return head;        
    }
    struct ListNode *p = head;
    while(r->next != NULL )
    {

        p = p->next;
        r = r->next;
    }
    r = p->next;
    p->next = r->next;
    free(r);
    return head;
}
```
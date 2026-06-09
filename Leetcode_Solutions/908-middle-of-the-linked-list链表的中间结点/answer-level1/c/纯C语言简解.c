### 解题思路
思路就是遍历链表的同时计数，这样可以提高效率

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    if(!head)
        return NULL;
    int cou = 0;
    struct ListNode *p = head;
    struct ListNode *q = head;
    while(q)
    {
        cou++;
        if(cou%2==0)
            p=p->next;
        q=q->next;
    }
    return p;
}
```




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
typedef struct ListNode Node;

struct ListNode* swapPairs(struct ListNode* head)
{
    if (!head || !head->next)
        return head;
    Node *res = head->next, *nt, *pre = NULL;
    while (head && head->next)
    {
        nt = head->next->next;
        head->next->next = head;
        if (pre)
            pre->next = head->next;
        head->next = nt;
        pre = head;
        head = nt;
    }
    return res;
}
```
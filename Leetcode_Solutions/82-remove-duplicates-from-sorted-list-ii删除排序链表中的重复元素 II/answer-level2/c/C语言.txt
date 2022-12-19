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


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *pre = NULL, *res = head, *del;
    while (head && head->next)
    {
        if (head->val == head->next->val)
        {
            while (head->next && head->val == head->next->val)
            {
                del = head;
                head = head->next;
                free(del);
            }
            del = head;
            head = head->next;
            free(del);
            if (pre)
                pre->next = head;
            else
                res = head;
        }
        else
        {
            pre = head;
            head = head->next;
        }
    }
    return res;
}
```
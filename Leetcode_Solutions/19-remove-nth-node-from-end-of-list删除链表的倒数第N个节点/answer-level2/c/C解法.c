### 解题思路
此题主要就是注意处理好边界问题。
另外，n大于链表长度，力扣的处理规则是，一律当成删除倒数最后（即第一个元素）。

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
    if (head == NULL || n <= 0)
        return head;
    struct ListNode *p = NULL, *q = NULL;
    struct ListNode *temp = NULL;
    p = head;
    for (int i = 0; i < n; i++)
    {
        p = p ->next;
        if (p == NULL)
        {
            temp = head;
            head = head ->next;
            free(temp);
            return head;
        }
    }
    q = head;
    while (p != NULL && p ->next != NULL)
    {
        p = p ->next;
        q = q ->next;
    }
    temp = q ->next;
    q ->next = q ->next ->next;
    free(temp);
    return head;
}

```
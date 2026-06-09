### 解题思路
直接用双指针找到相应的节点，一次旋转完成

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
struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (!head)
        return NULL;
    Node *left = head, *right = head;
    for (int i = 0; i < k; i++)
        if (right->next)
            right = right->next;
        else
        {
            right = head;
            k %= (i + 1);
            i = -1;
        }
    while (right->next)
    {
        left = left->next;
        right = right->next;
    }
    right->next = head;
    head = left->next;
    left->next = NULL;
    return head;
}
```
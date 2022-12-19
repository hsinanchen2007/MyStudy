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


struct ListNode* middleNode(struct ListNode* head) 
{
    int cnt = 1;
    struct ListNode *node = 0;
    struct ListNode *tmp = head;

    node = tmp;
    while (tmp) {
        if (cnt % 2 == 0) {
            node = node->next;
        }
        cnt++;
        tmp = tmp->next;
    }

    return node;
}
```
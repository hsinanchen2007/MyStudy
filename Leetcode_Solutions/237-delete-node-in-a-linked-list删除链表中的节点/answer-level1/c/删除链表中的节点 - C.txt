### 解题思路
不需要考虑head，只要考虑如何把当前节点的指向指到next节点，已经下一个节点执行下一个节点的值。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
    return ;
}
```
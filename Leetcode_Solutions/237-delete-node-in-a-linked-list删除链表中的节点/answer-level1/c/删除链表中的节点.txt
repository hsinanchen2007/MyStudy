### 解题思路
将后一个结点的状态复制到当前结点，删除后一个结点即可
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
    struct ListNode* p = node->next;
    node->val = p->val;
    node->next = p->next;
    free(p);
}
```
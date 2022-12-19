### 解题思路
没有head指针，传入参数仅仅是要删除的节点的地址。
用下一个节点的值替换形参节点，删除形参节点的下一个节点。

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
    struct ListNode *iter=node->next;
    node->val=iter->val;
    node->next=iter->next;
    free(iter);
}
```
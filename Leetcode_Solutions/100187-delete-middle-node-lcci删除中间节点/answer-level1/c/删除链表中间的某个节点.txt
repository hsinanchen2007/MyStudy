### 解题思路
形参就是要删除的节点地址
把下一个节点的值复制到当前节点中，删除下一个节点即可

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
    node->val=node->next->val;
    struct ListNode* del=node->next;
    node->next=del->next;
    free(del);
}
```
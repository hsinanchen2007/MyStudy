### 解题思路
把下一节点的值挪到当前位置
然后删除下一节点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
void deleteNode(struct ListNode* node) {
    node->val=node->next->val;
    ListNode*t=node->next;
    node->next=t->next;
    free(t);
}
```
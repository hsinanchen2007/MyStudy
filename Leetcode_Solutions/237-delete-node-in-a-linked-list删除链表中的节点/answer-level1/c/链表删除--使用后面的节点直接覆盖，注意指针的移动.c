### 解题思路
使用后一个节点直接覆盖就可以了。
不熟悉的话，指针移动最好画下图。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) 
{
    node->val = node->next->val; //使用后一个节点覆盖
    node->next = node->next->next;
    return;
}
```
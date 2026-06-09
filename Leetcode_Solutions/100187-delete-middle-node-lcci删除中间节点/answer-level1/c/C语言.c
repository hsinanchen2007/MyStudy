### 解题思路
此处撰写解题思路

（1）将node后边的结点值赋值给当前结点；
（2）架空node后边的结点

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

}
```
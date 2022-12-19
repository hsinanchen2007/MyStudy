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
// node是待删除节点，头节点不知道
void deleteNode(struct ListNode* node) {
    // 直接把值替换掉
    node -> val = node -> next -> val;
    // if ( node -> next -> next )
        node -> next = node -> next -> next;    // 这里不需要考虑边界情况
}
```
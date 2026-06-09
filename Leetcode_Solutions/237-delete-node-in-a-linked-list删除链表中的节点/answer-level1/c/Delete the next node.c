### 解题思路
As been told the node of a singly-linked list, we can operate the node or the next node;

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /* Without the node before this node, we can't delete this node */
void deleteNode(struct ListNode* node) {
    struct ListNode*temp=node->next;    // Save next node as temp
    node->val=temp->val;                // Copy the value of next node to the value of this node
    node->next=temp->next;              // Delete next node
    free(temp);                         // Free next node
}
```
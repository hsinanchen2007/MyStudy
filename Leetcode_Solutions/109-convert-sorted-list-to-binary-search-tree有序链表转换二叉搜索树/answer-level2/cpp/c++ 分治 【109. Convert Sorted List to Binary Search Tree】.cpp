### 解题思路
1. 如果当前head为null，返回null；否则使用快慢指针找到中间节点。
2. 为中间节点的值创建树节点，并以中间节点将原链表分割成两部分。
2. 递归处理两个子问题，将其返回作为根的左右子树

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    if (!head) return 0;
        ListNode* p = head;
        ListNode* q = p;
        ListNode* pre = 0;
        while (q && q->next) {
            q = q->next->next;
            pre = p;
            p = p->next;
        }
        if (pre) pre->next = 0;
        TreeNode* node = new TreeNode(p->val);
        node->left = sortedListToBST(head == p ? pre : head);
        node->right = sortedListToBST(p->next);
        return node;
};
```
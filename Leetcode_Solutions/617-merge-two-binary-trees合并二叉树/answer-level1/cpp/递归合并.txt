### 解题思路
直接看代码吧，挺简单的递归题

### 代码

```cpp
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1)
        {
            return t2;
        }
        if(!t2)
        {
            return t1;
        }
        TreeNode* head = new TreeNode(t1->val+t2->val);
        head->left=mergeTrees(t1->left,t2->left);
        head->right=mergeTrees(t1->right,t2->right);
        return head;
        
    }
};
```
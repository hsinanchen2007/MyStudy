### 解题思路
递归回溯

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
    bool judge(TreeNode* l, TreeNode* r)
    {
        if(l == NULL && r == NULL) return true;
        if(l == NULL || r == NULL) return false;
        if(l -> val != r -> val) return false;
        return judge(l -> right, r -> left) & judge(l -> left, r -> right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return judge(root -> left, root -> right);
    }
};
```
### 解题思路
树是递归定义的数据结构，首先考虑特殊情况，即叶子结点的表示：左，右叶子分别为空则为叶子结点，此时取出左边叶子结点的值。然后递归调用函数取出每一棵子树的左叶子的值进行求和。
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        if(root->left && !root->left->left && !root->left->right){
            sum = root->left->val;
        }
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
```
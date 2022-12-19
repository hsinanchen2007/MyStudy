### 解题思路
子树为空时用null填充，将路径和作为参数传进函数，当函数的根参数为空时，说明已走到底层null结点，判断add与待判断sum值是否相同；注意此时并不一定是叶子节点下面的null,也有可能是单子树结点的另一侧null,要注意区分，是否存在路径取决于叶子节点add,而要排除掉单子树结点的add。

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        int add = 0;
        return hasPathSumHelp(root, sum, add);
    }

    bool hasPathSumHelp(TreeNode* root, int sum, int& add)
    {
        if(!root)
        {
            if(add == sum) return true;
            else return false;
        }

        add += root->val;
        int left = add;
        int right = add;
        int leftbool = hasPathSumHelp(root->left, sum, left);
        int rightbool = hasPathSumHelp(root->right, sum, right);
        if(!(root->left) && root->right) return rightbool;//*注意单子树的情况，取决于非空有子树一侧
        if(root->left && !(root->right)) return leftbool;//*单子树
        return leftbool || rightbool;
    }
};
```
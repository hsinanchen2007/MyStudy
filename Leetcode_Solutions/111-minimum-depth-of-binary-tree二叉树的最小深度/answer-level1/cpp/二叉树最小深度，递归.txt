### 解题思路
类似求树的高度，只不过取得是左右子树高度小的加一。特别注意：若是单分支，不能取空分支的高度加一，要取非空分支的高度加一，因为求的是到叶节点的距离。

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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int lefth = minDepth(root->left);
        int righth = minDepth(root->right);
        if(lefth==0 || righth==0)
            return lefth + righth + 1;
        return min(lefth, righth) + 1; 
    }
};
```
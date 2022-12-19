### 解题思路
如果root位空，那么一定false;
否则使用深度优先搜索。

注意：结点的val可能为正数或负数或零。

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
        if(root==NULL)
            return false;
        return depth(root,sum);
    }

    bool depth(TreeNode * root, int sum){
        if(root==NULL)
            return false;
    
        sum = sum-root->val;
        if(sum==0){
            if(root->left==NULL && root->right==NULL)  //判断是否位叶子结点
                return true;
        }  
        
        bool left = depth(root->left,sum);
        bool right = depth(root->right,sum);
       if(left || right)
            return true;  //左子树或右子树中有一条路径可以到叶结点时sum==0
        return false;
    }
};
```
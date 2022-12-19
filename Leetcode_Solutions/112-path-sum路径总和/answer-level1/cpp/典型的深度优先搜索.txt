### 解题思路
1、判断边界条件。1）root为null。2）root左右子树为null。
2、深度搜索左右子树。

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
    bool DFS(TreeNode* root, int sum){
        if(root == NULL){
            return false;
        }
        if(!root->left &&!root->right){
            if(root->val == sum){
                return true;
            }
        }
        return (DFS(root->left, sum-root->val) || DFS(root->right, sum -root->val));
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return DFS(root, sum);
    }
};
```
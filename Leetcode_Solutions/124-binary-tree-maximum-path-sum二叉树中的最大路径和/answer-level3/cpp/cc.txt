### 解题思路
此处撰写解题思路

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

    int ans = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        dfs(root); 
        return ans;
    }
    int dfs(TreeNode* root){
        if(!root)return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        ans = max(ans,left+right+root->val);
        //路径和最小为0
        return max(root->val+max(left,right),0);
    }
};
```
### 解题思路
dfs
到了叶节点就比较一下

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
    int f=0;
    void dfs(TreeNode* root,int cnt,int sum){
        if(!root) return ;
        if(!root->left&&!root->right){
            if(sum==cnt+root->val) f=1;
            return ;
        }
        dfs(root->left,cnt+root->val,sum);
        dfs(root->right,cnt+root->val,sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        dfs(root,0,sum);
        if(f) return true;
        return false;
    }
};
```
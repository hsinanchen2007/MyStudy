### 解题思路
DFS求经过每个节点的最大值中的最大值即可，中间有重复子问题加以利用就可以了。

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
    int res=0;
    int maxPathSum(TreeNode *root) {
        res=root->val;
        dfs(root);
        return res;
    }   
    int dfs(TreeNode *t){
        if(!t)return 0;
        int l=dfs(t->left),r=dfs(t->right);
        res=max(t->val+l+r,res);
        return max(max(max(l+t->val,r+t->val),t->val),0);
    }
};
```
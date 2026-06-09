### 解题思路
根据二叉搜索树的特点，中序遍历的值是从小到大排列的。

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
    void dfs(TreeNode* root,vector<int> &ans) 
    {
        if(root != NULL)
        {
            dfs(root -> left,ans);
            ans.push_back(root -> val);
            dfs(root -> right,ans);
        }

    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL || k == 0)
            return -1;
        vector<int > ans;
        dfs(root,ans);
        return ans[k - 1];

    }
};
```
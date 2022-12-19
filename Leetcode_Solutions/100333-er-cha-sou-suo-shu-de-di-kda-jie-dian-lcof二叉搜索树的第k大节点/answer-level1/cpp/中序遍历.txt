### 解题思路
二叉搜索树中序遍历得到的即为有序序列

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
    vector<int> res;
    void dfs(TreeNode* root){
        if(root==NULL)
            return;
        dfs(root->right);
        res.push_back(root->val);
        dfs(root->left);
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        return res[k-1];
    }
};
```
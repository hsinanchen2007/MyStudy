### 解题思路
写一个dfs函数并用数组记录两个数的叶值序列（即叶子节点），之后比较两个数组是否相同即可。

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
    void dfs(TreeNode* root,vector<int>&res){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            res.push_back(root->val);
        }
        dfs(root->left,res);
        dfs(root->right,res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>res1;
        vector<int>res2;
        dfs(root1,res1);
        dfs(root2,res2);
        return res1==res2;
    }
    
};
```
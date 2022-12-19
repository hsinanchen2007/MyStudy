### 解题思路
将每个节点放入数组，中序遍历后数组为递增次序，输出从end起的第K个即可。

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
    int kthLargest(TreeNode* root, int k) {
        vector<int>res;
        dfs(root,res);
        return res[res.size()-k];
    }

    void dfs(TreeNode*root,vector<int>&res){
        if(root==NULL){
            return;
        }
        dfs(root->left,res);
        res.push_back(root->val);
        dfs(root->right,res);
    }
};
```
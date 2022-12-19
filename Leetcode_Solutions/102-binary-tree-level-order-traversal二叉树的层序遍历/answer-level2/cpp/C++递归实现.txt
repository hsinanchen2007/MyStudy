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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root){
           helper(root,0);
        }
        return res;

    }

    void helper(TreeNode* root,int level){
        if(root==NULL) return;
        if(res.size()==level){
            vector<int> tmp;
            res.push_back(tmp);
        }
        res[level].push_back(root->val);
        if(root->left){
            helper(root->left,level+1);
        }
        if(root->right){
            helper(root->right,level+1);
        }
    }
};
```
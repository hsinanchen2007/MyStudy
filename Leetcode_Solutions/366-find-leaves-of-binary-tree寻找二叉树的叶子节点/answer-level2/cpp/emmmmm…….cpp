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
class Solution{
public:
    vector<vector<int>>res;
    vector<int>m;
    unordered_map<TreeNode*,int> map;
    vector<vector<int>> findLeaves(TreeNode* root){
        TreeNode* store=root;
        if(!root) return res;
        while(store->left||store->right){
            a(root);
            res.push_back(m);
            m.clear();
            fix(root);
        }
        res.push_back({root->val});
        return res;
    }
    void a(TreeNode* root){
        if(root){
            if(!root->left&&!root->right) {
                m.push_back(root->val);
                map[root]+=1;
            }
            a(root->left);
            a(root->right);
        }
    }
    void fix(TreeNode* root){
        if(root){
            if(root->left&&map[root->left]==1) root->left= nullptr;
            if(root->right&&map[root->right]==1) root->right= nullptr;
            fix(root->left);
            fix(root->right);
        }
    }
};
```
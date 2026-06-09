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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int height = getHeight(root);
        vector<vector<TreeNode*>> p(height);
        vector<vector<int>> res(height);
        if(height==0) return res;
        res[0].push_back(root->val);
        p[0].push_back(root);

        for(int i=1;i<p.size();i++){
            for(int j=0;j<p[i-1].size();j++){
                if(p[i-1][j]->left!=NULL){
                    p[i].push_back(p[i-1][j]->left);
                    res[i].push_back(p[i-1][j]->left->val);
                }
                if(p[i-1][j]->right!=NULL){
                    p[i].push_back(p[i-1][j]->right);
                    res[i].push_back(p[i-1][j]->right->val);
                }
            }
            if(i%2==1) reverse(res[i].begin(),res[i].end());
        }
        return res;
    }

    int getHeight(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return max(getHeight(root->left),getHeight(root->right))+1;
    }
};
```
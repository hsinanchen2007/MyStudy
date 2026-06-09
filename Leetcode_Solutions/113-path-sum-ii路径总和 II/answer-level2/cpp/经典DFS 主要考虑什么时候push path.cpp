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
    vector<vector<int>> res;
    vector<int> path;
    int path_sum;
    int sum;
    void DFS(TreeNode* root){
        if(root){
            path.emplace_back(root->val);
            path_sum += root->val;
            if(!root->left && !root->right && path_sum == sum){
                res.emplace_back(path);
            }
            else{
                DFS(root->left);
                DFS(root->right);
            }
            path.pop_back();
            path_sum -= root->val;
        }
        else return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        this->sum = sum;
```
代码块
```
        DFS(root);
        return res;
    }
};
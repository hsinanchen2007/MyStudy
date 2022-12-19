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
    //迭代解法
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        stack<pair<TreeNode*, int>> stk;//将节点与到该节点的路径和绑定
        stk.push({root, root->val});

        while(!stk.empty()){
            pair<TreeNode*, int> node = stk.top();
            stk.pop();
            if(!node.first->left && !node.first->right && node.second==sum){
                return true;
            }
            if(node.first->right){
                stk.push({node.first->right, node.second+node.first->right->val});
            }
            if(node.first->left){
                stk.push({node.first->left, node.second+node.first->left->val});
            }
        }
        return false;
    }
};
```
用两个栈，一个从左往右（初始压入root节点），一个从右往左的，代码如下：
```
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
        vector<vector<int>> results;
        if(root == nullptr) return results;
        stack<TreeNode*> l2r, r2l;
        l2r.push(root);
        int layer = -1;
        while(!l2r.empty()) {
            layer++;
            results.emplace_back();
            while(!l2r.empty()) {
                root = l2r.top(); l2r.pop();
                results[layer].push_back(root->val);
                if(root->left) r2l.push(root->left);
                if(root->right) r2l.push(root->right);
            }
            if(r2l.empty()) break;
            layer++;
            results.emplace_back();
            while(!r2l.empty()){
                root = r2l.top(); r2l.pop();
                results[layer].push_back(root->val);
                if(root->right) l2r.push(root->right);
                if(root->left) l2r.push(root->left);
            }
        }
        return results;
    }
};
```

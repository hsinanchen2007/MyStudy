二叉搜索树的中序遍历
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        stack<TreeNode*> sta;
        TreeNode *p=root;
        while(p || !sta.empty()){
            while(p) {
                sta.push(p);
                p=p->left;
            }
            if(!sta.empty()){
                p=sta.top();
                sta.pop();
                res.push_back(p->val);
                p=p->right;
            }
        }
        return res[k-1];
    }
};
```
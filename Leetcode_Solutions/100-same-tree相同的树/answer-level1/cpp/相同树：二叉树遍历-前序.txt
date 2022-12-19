C++提交击败前91%。相同树原理其实就是同时对两颗树进行遍历，只要发生1、两树结点值不一样；2、两树左右儿子存在不一致 两种情况的一样就返回false;
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
    bool preoder(TreeNode* root, TreeNode* c_root) {
        if(root==NULL||c_root==NULL) {
            if(root==NULL&&c_root==NULL) return true;
            return false;
        }
        if(root->val!=c_root->val) return false;
        bool left = preoder(root->left, c_root->left);
        bool right = preoder(root->right, c_root->right);
        return (left&&right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preoder(p, q);
    }
};
```

// 递归做法
```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorderTraversalCore(root,ret);
        return ret;
    }

    void preorderTraversalCore(TreeNode* root,vector<int> & ret) {
        if (root == NULL) return;
        ret.push_back(root->val);
        preorderTraversalCore(root->left,ret);
        preorderTraversalCore(root->right,ret);
    }
};
```
// 非递归做法，借助栈的使用
```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        if (root == NULL) return ret;
        stk.push(p);
        while (!stk.empty()) {
            TreeNode* tmp = stk.top();
            ret.push_back(tmp->val);
            stk.pop();
            if (tmp->right) {
                stk.push(tmp->right);
            }
            if (tmp->left) {
                stk.push(tmp->left);
            }
        }
        return ret;
    }
};
```

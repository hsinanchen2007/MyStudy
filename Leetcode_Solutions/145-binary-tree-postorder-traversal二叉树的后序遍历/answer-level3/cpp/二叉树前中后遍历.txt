### 解题思路
和前序中序遍历类比，后序遍历需要额外创建一个节点判断子节点是否还有右孩子。
整体代码：
class Solution {
public:
    //前序遍历
    //递归，就是回溯的一种
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        backtrace(root, res);
        return res;
    }
    void backtrace(TreeNode* node, vector<int>& res) {
        if (node != NULL) {
            int val = node->val;
            res.push_back(val);
        } else {
            return;
        }
        backtrace(node->left, res);
        backtrace(node->right, res);
    }
    //迭代，利用栈思想
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sk;
        while(root||sk.size()) {
            while(root) {
                sk.push(root);
                res.push_back(root->val);
                root = root->left;
            }
            root = sk.top();
            sk.pop();
            root = root->right;
        }
        return res;

    //中序遍历
    //递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        backtrace(res, root);
        return res;
    }
    void backtrace(vector<int>& res, TreeNode* root) {
        if (root == NULL) return;
        if (root->left) backtrace(res, root->left);
        res.push_back(root->val);
        if (root->right) backtrace(res, root->right);
    }
    //迭代
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sk;
        while(root || sk.size()) {
            while(root) {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            sk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }

    //后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sk;
        TreeNode* pre = NULL;
        while(root || sk.size()) {
            while(root) {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            if (root->right == NULL || pre == root->right) {
                sk.pop();
                res.push_back(root->val);
                pre = root;
                root = NULL;
            } else {
                root = root->right;
                pre = NULL;
            }
        }
        return res;
};

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sk;
        TreeNode* pre = NULL;
        while(root || sk.size()) {
            while(root) {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            if (root->right == NULL || pre == root->right) {
                sk.pop();
                res.push_back(root->val);
                pre = root;
                root = NULL;
            } else {
                root = root->right;
                pre = NULL;
            }
        }
        return res;
    }
};
```
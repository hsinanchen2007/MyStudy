### 解题思路
5种写法见注释咯

### 代码

```cpp
/************************
 * 二叉树的先序遍历
 * 
 ***********************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**********************
 * 递归写法1：执行用时0ms
 *********************/
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
        vector<int> res;
        int first = root->val;
        res.push_back(first);
        auto left = preorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());
        auto right = preorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};

/**********************
 * 递归写法2：执行用时4ms
 * 不用调用insert方法，写法最简洁，容易理解
 *********************/
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderTraversal_1(root, res);
        return res;
    }

    void preorderTraversal_1(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        preorderTraversal_1(root->left, res);
        preorderTraversal_1(root->right, res);
    }
};

/**********************
 * 非递归写法1：执行用时4ms
 * 右节点入栈
 *********************/
class Solution3 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> visiting;
        visiting.push(NULL);
        while(root) {
            res.push_back(root->val);
            if(root->right) {
                visiting.push(root->right);
            }
            if(root->left) {
                root = root->left;
            }else{
                root = visiting.top();
                visiting.pop();
            }
        }
        return res;
    }
};

/**********************
 * 非递归写法2：执行用时0ms
 * 左节点入栈
 *********************/
class Solution4 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> visiting;
        while(root || visiting.size()) {
            while (root) {
                res.push_back(root->val);
                visiting.push(root);
                root = root->left;
            }
            if(visiting.size()) {
                root = visiting.top();
                visiting.pop();
                root = root->right;
            }
        }
        return res;
    }
};

/**********************
 * 非递归写法3：执行用时0ms，空间复杂度O(1)，最优算法
 * Morris 先序遍历算法
 * 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点；
 * 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。(即当前节点的左子节点一路向右)
 *   a). 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。输出当前节点。当前节点更新为当前节点的左孩子。
 *   b). 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。当前节点更新为当前节点的右孩子。
 * 3. 重复以上1、2直到当前节点为空
 *********************/
class Solution5 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* temp;
        while(root) {
            if(!root->left) {
                res.push_back(root->val);
                root = root->right;
            } else {
                temp = root->left;
                while(temp->right && temp->right!=root) {
                    temp = temp->right;
                }
                if(temp->right == root) {
                    temp->right = NULL;
                    root = root->right;
                }else{
                    temp->right = root;
                    res.push_back(root->val);
                    root = root->left;
                }
            }
        }
        return res;
    }
};

```
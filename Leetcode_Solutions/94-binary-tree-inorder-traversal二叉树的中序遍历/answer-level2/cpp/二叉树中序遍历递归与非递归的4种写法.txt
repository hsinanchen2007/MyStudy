## 二叉树中序遍历递归与非递归的4种写法
递归写法两种比较简单。非递归写法分别使用了栈和Morris算法
## 包含注释源码
```cpp
/************************
 * 二叉树的中序遍历
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
 * 递归写法1：执行用时4ms
 *********************/
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        auto left = inorderTraversal(root->left);
        auto right = inorderTraversal(root->right);
        left.push_back(root->val);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

/**********************
 * 递归写法2：执行用时4ms
 * 不用调用insert方法，写法最简洁，容易理解
 *********************/
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) res;
        inorderTraversal_1(root, res);
        return res;
    }
    void inorderTraversal_1(TreeNode* root, vector<int>& res) {
        if(!root) return;
        inorderTraversal_1(root->left, res);
        res.push_back(root->val);
        inorderTraversal_1(root->right, res);
    }
};


/**********************
 * 非递归写法1：执行用时4ms
 * 左节点入栈
 *********************/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> visiting;
        while(root || visiting.size()) {
            while (root) {
                visiting.push(root);
                root = root->left;
            }
            if(visiting.size()) {
                root = visiting.top();
                res.push_back(root->val);
                visiting.pop();
                root = root->right;
            }
        }
        return res;
    }
};

/**********************
 * 非递归写法2：执行用时0ms
 * Morris 先序遍历算法
 * 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点；
 * 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。(即当前节点的左子节点一路向右)
 *   a). 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
 *   b). 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。输出当前节点。当前节点更新为当前节点的右孩子。
 * 3. 重复以上1、2直到当前节点为空
 *********************/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* temp;
        while(root) {
            if(!root->left) {
                res.push_back(root->val);
                root = root->right;
            } else {
                temp = root->left;
                while(temp->right && temp->right!=root)
                    temp = temp->right;
                if(!temp->right) {
                    temp->right = root;
                    root = root->left;
                } else {
                    temp->right = NULL;
                    res.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return res;
    }
};
```

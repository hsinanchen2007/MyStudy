### 解题思路
树的递归两种方式：
（1）travel 方式，这种递归方程无需返回值，但是需要传引入保存travel路径的容器；
（2）分治方式，这种递归，需要返回值；


本题是用travel的方式：
需要传入vector 保存路径；
前序：   
        result.push_back(root->val);
        preorderTraversal(root->left, result);
        preorderTraversal(root->right, result);
中序：
        preorderTraversal(root->left, result);
        result.push_back(root->val);
        preorderTraversal(root->right, result);
后序：
        preorderTraversal(root->left, result);
        preorderTraversal(root->right, result);
        result.push_back(root->val);

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversal(root, result);
        return result;
    }

    void preorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        result.push_back(root->val);
        preorderTraversal(root->left, result);
        preorderTraversal(root->right, result);
    }
};
```
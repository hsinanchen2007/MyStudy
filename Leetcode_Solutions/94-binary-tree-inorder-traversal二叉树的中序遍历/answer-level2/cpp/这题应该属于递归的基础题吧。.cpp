### 解题思路
树的遍历：
前序：
void fun(tree){
    tree->val;
    fun(tree->left);
    fun(tree->right);
}
中序：
void fun(tree){
    fun(tree->left);
    tree->val;
    fun(tree->right);
}
后序：
void fun(tree){
    fun(tree->left);
    fun(tree->right);
    tree->val;
}

![image.png](https://pic.leetcode-cn.com/baf735c4ee65416a0ecde82f829952be22e674343e38bedf4ea8de1eaa5e77b8-image.png)


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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return res;
        }
        if(root->left) inorderTraversal(root->left);
        res.push_back(root->val);
        if(root->right) inorderTraversal(root->right);
        return res;
    }

};
```
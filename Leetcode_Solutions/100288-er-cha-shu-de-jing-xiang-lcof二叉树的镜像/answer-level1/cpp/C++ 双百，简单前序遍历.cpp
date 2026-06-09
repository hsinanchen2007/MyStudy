### 解题思路
简单的前序遍历即可
![image.png](https://pic.leetcode-cn.com/43d15bb2ab1ce9275e9c778c569a522ba0f0b5f7b570e9596dc9d10bd066aa7f-image.png)


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
    void order(TreeNode *root) {
        if (root != nullptr) {
            swap(root->left, root->right);
            order(root->left);
            order(root->right);
        }
    }

    TreeNode* mirrorTree(TreeNode* root) {
        order(root);
        return root;
    }
};
```
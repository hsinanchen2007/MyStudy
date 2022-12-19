### 题目
给定一个二叉树，其中所有的右节点要么是具有兄弟节点（拥有相同父节点的左节点）的叶节点，要么为空，将此二叉树上下翻转并将它变成一棵树， 原来的右节点将转换成左叶节点。返回新的根。

### 解题思路
![无标题.png](https://pic.leetcode-cn.com/1f53b29dad8a4320228b8ccb1886b0e4c6eafe41972fb4bc9df40f926e78d047-%E6%97%A0%E6%A0%87%E9%A2%98.png)


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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode * tmp;
        TreeNode * resultfromLeft;
        if(root == NULL || root->left == NULL) return root;
        resultfromLeft = upsideDownBinaryTree(root->left);
        tmp = resultfromLeft;
        while(tmp->right != NULL) tmp = tmp->right;
        tmp->right = root;
        tmp->left = root->right;
        root->left = root->right = NULL;
        return resultfromLeft;
    }
};
```
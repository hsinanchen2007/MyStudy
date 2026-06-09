### 解题思路
非常简单的递归
![Screenshot from 2020-03-19 17-00-57.png](https://pic.leetcode-cn.com/5a23c31cd825ef807679d101b7759e16b8e8e1d3e2e1184c97c4322fab214abd-Screenshot%20from%202020-03-19%2017-00-57.png)


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
 //递归调用自身交换左子树和右子树
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;

    }
};
```
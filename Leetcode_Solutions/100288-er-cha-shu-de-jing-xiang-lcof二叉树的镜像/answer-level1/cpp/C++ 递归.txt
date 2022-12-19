### 解题思路
![image.png](https://pic.leetcode-cn.com/0a004e82bae055d37f27808f7d6cf1e5b4e88d16ffc246deb15e51b310dcc242-image.png)
思路很简单，一棵树和它的镜像之间的关系：根节点相同，树的左子树和它的镜像的右子树互为镜像，树的右子树和它镜像的左子树互为镜像。

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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        TreeNode* r = new TreeNode(root->val);
        r->left = mirrorTree(root->right);
        r->right = mirrorTree(root->left);
        return r;
    }
};
```
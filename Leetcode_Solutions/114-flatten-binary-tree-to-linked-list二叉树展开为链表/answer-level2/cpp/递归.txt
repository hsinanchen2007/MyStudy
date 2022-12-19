### 解题思路
递归

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
    void flatten(TreeNode* root) {
        if (root == NULL)
        {
            return;
        }
        //左右子树
        TreeNode *left = root->left;
        TreeNode *right = root->right;

        flatten(left);//左子树flatten
        root->left = NULL;//清空root的左儿子
        root->right = left;//右儿子接上平了的左子树
        //获得平了的左子树的最右一个儿子节点
        TreeNode *p = root;
        while (p->right != NULL)
        {
            p = p->right;
        }
        flatten(right);//右子树flatten
        p->right = right;//平了的右子树接到平了的左子树的最右节点上
    }
};
```
### 解题思路
递归过程中边修改子数，边返回子数中1的个数

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
    int countOne(TreeNode** root) {
        if (*root == NULL) return 0;
        int l = countOne(&(*root)->left);
        int r = countOne(&(*root)->right);
        int res = l + r + (*root)->val;
        if (res == 0) {
            *root = NULL;
        }
        return res;
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode** pnode = &root;
        countOne(pnode);
        return *pnode;
    }
};
```

![image.png](https://pic.leetcode-cn.com/443077f38e290c711189c29256386236acd2c0c77f48b6fd0f9a54fdebbaf3fe-image.png)

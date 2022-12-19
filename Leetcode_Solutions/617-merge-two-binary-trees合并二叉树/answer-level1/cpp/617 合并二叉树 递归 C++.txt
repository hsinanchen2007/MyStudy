### 解题思路
![image.png](https://pic.leetcode-cn.com/e110da56b94e5ee68b33dceb49869429e1bfca6aae3150dec0cd1cc0be1ca5ea-image.png)

1.若t1空，返回t2
2.左子树为二者左子树的合并，右子树为右子树的合并
3.val为加和

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        t1->val = t1->val +t2->val;
        return t1;
    }
};
```
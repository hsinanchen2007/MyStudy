### 解题思路
如标题一般 就是简单的看两个树是否相等 只不过是 当一个遍历左子树的时候 另外一个遍历右子树而已
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
    bool isSame(TreeNode *root1,TreeNode *root2)
    {
        return (root1==NULL&&root2==NULL)||(root1!=NULL&&root2!=NULL&&root1->val==root2->val&&isSame(root1->left,root2->right)&&isSame(root1->right,root2->left));
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root,root);
    }
};
```
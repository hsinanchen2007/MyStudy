### 解题思路
左面的一定和右面的相等就对称了。
看代码吧。

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
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return isSame(root,root);
    }
    bool isSame(TreeNode *A,TreeNode *B){
        bool a=(A->left)&&(B->right)?(A->left->val==B->right->val)&&isSame(A->left,B->right):!((A->left)||(B->right));
        bool b=(A->right)&&(B->left)?(A->right->val==B->left->val)&&isSame(A->right,B->left):!((A->right)||(B->left));
        return a&&b;
    }
};
```
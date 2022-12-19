### 解题思路
1. 在`root`的左子树和右子树同时找`p`和`q`，若`p`和`q`分别分布在`root`的左右子树，则`root`为所求
2. 若左子树返回`NULL`，则说明`p`和`q`都在右子树，则进入右子树做`1.`
3. 若右子树返回`NULL`，则说明`p`和`q`都在左子树，则进入左子树左`1.`
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //先找到p或者q就返回
        if(root == NULL || root == p || root == q) return root;
        //在左子树找p或q，假如p和q都在左子树，返回的那个值就是祖先
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        //在右子树找p或者q，假如p和q都在右子树，返回的那个值就是祖先
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL) return right;
        if(right == NULL) return left;
        // p和q一个在左子树一个在右子树
        return root;
    }
};
```
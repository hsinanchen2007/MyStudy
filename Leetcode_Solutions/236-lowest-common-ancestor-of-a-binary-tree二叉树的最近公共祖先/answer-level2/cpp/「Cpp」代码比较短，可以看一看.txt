### 解题思路

p和q只有两种情况

- 其中一方是一方的父节点，
- 两个是同一个父节点的后代

因此，分别从左右子树上找p和q，找到之后返回p和q所在节点。如果找不到返回是NULL

如果两个都找到，那么`left != nullptr && right != nullptr`, 当前的root就是LCA。否则，就看哪个节点找到了p或q，找到的位置就是p和q的LCA。


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
        //如果当前节点为空, 或者是p,q的一个，返回该节点
        if( root == nullptr|| root == p || root == q){
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        //在左右分别找到了p和q, 那么当前节点就是LCA
        if ( left != nullptr && right != nullptr) {
            return root;
        }
        // 否则说明，在一边上找到了p和q，第一个找到的节点就是LCA
        return left != nullptr ? left : right;
        
    }
};
```
### 解题思路
题目要求是返回二叉树的最近公共祖先。
给定了两个指针。
首先**最近公共祖先**的分布只能有3种情况，在左子树中，在右子树中，就是自己。
结果只能是在上面三种情况中的一个，不能同时存在。
换句话说：
    1. 如果在左子树中找到了，那么右子树中一定找不到，右子树中一定返回空。
    2. 如果在右子树中找到了，那么左子树中一定找不到，左子树中一定返回空。
    3. 如果左右子树都找到了，那么一定说明左右子树中找到的都只是p或者q，那么当前的root就是公共节点。
    4. 如果左右子树都没找到，那么看root是否等于p或者q是的话就返回，不是就返回空。

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
        if(root == NULL || root == p || root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left == NULL){
            return right;
        }else if(right==NULL){
            return left;
        }else{
            return root;
        }
    }
};
```

### 3个月后的再次理解
所谓找**公共最近公共祖先**，其实可以理解为**就是找两个节点**
找到了就返回这个节点。
在左右子树中分别去找。

**因为我们发现一个其中节点之后立刻就返回了**。
并且在返回后还会根据两侧的情况进行调整，从而自底向上，始终返回的最近公共祖先节点。
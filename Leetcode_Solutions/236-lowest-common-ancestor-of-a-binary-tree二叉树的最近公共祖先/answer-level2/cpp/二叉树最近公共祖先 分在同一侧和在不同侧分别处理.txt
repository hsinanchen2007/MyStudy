### 解题思路
二叉树最近公共祖先 分在同一侧和在不同侧分别处理
关键是要先 递归求出左右侧的公共祖先
如果在同一侧，表现就是递归的左右侧公共祖必然先有一个为空，不为空的就是结果
如果在不同侧，表现就是递归的左右侧公共祖都不为空，则root就是公共祖先

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
        if(root==NULL) return NULL;
        if(p == root || q == root ) return root;     /* 有一个为root公共祖先就是root节点*/
        TreeNode *left = lowestCommonAncestor(root->left, p, q);  /* 递归求出左侧的公共祖先*/
        TreeNode *right = lowestCommonAncestor(root->right, p, q);   /* 递归求出右侧的公共祖先*/
        if (left && right) return root;  /*p q在root不同侧，公共祖先就是root */
        return left ? left : right;  /*p q在root同一侧，就返回同一侧的递归结果（都在左侧，右侧的递归结果就为空，返回左侧的递归结果；反之亦然）*/

    }
};
```
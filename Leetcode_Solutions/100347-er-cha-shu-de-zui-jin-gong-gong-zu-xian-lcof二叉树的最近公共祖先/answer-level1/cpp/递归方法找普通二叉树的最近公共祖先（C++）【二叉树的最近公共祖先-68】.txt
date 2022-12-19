### 解题思路
二叉树考虑**递归方法。**
1. 边界条件：
   - 如果当前root为空，即二叉树已经走到了叶子，返回null；
   - 如果当前root为q或者P,即查找到的地方这条路上有p或者q，所以向上返回root，即告诉上层，这条路上包含着p或者q.
2. 然后考虑整体操作框架：
   - 判断完两个边界条件；
   - 如果都不符合，那么去左子树中找，返回的节点放到left，如果这一路上没有我们要找的p,q，最后left就为空；
   - 然后去右子树中找，同样的道理；
   - 最后判断：如果当前root的左右子树返回的left,right都不为空，说明下面两条路上都有我们要的，所以当前节点即为答案，返回root;
   - 但是，因为递归，这个答案会一直往上层走，但是到了更上层以后，因为下面才是公共祖先，所以会出现left和rihgt中间只有一个不为空，即存放着答案，另一个为空，即那一路上q,p都没有。所以返回有内容的left/right.
   - 最后结束。

**考虑二叉树递归时，就当成在处理一个节点时的操作步骤即可！考虑好边界条件和整体处理流程！**

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
        if(root==NULL)  return NULL;
        if(root==p||root==q) return root;
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if(left&&right)  return root;  //当root两侧都不为空，即拥有p或者q，时，当前root即为解；
        return left?left:right;
    }
};
```
### 解题思路
递归处理，具体参见代码注释

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
        if(root==NULL|root==p||root==q)//当前节点为空或者就是要查找的某个节点则直接返回
            return root;
        //否则在左右子树中查找
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        //如果在左子树和右子树中的查找结果都是非空，则说明在左右子树中已查找到对应节点，则当前节点就是最近公共祖先，直接返回当前节点
        if((left!=NULL)&&(right!=NULL))
            return root;
        //否则就是只找到一个，则只返回找到的这个节点
        return left!=NULL?left:right;
    }
};
```
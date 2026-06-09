### 解题思路
此处撰写解题思路

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
    //求公共祖先的通用递归解法
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //递归结束条件
        if(root == NULL|| root == p|| root == q)
        {
            return root;
        }
        TreeNode* leftAncestor = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAncestor = lowestCommonAncestor(root->right,p,q);

        //左边没有节点祖先
        if(leftAncestor == NULL)
        {
            return rightAncestor;
        }
        //右边没有节点祖先
        if(rightAncestor == NULL) 
        {
            return leftAncestor;
        }
        //两边都有节点祖先
        return root;
    }
};
```
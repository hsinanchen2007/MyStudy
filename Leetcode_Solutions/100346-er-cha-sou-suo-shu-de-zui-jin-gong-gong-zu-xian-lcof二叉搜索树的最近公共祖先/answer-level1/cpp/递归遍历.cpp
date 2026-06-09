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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q)
        {
            return root;
        }

        auto leftNode=lowestCommonAncestor(root->left,p,q);//auto 为自动推导类型
        auto rightNode=lowestCommonAncestor(root->right,p,q);
        
        if(!leftNode)
        {
            return rightNode;
        }
        if(!rightNode)
        {
            return leftNode;
        }
        return root;
    }
};
```
//递归遍历 先找出出口的情况 然后若左侧为空 则公共祖先在右侧 若右侧为空 则公共祖先在左侧
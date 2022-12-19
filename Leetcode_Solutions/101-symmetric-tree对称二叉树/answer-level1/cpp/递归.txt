### 解题思路
递归 ，主要的难点就是要确定是传入两个Node，传一个做不出来，然后比较的话是比较左数右节点-右数左节点，左数左节点-右数右节点
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
    bool checkNode(TreeNode* p,TreeNode* q)
    {
        if(NULL == p &&NULL == q)
        {
            return true;
        }
        if((NULL == p && NULL != q)|| (NULL == q &&NULL != p))
        {
            return false;
        }
        if(p->val != q->val)
        {
            return false;
        }
        if(checkNode(p->left,q->right) &&checkNode(p->right,q->left))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(NULL == root){return true;}

        return checkNode(root->left,root->right);
        
    }
};
```
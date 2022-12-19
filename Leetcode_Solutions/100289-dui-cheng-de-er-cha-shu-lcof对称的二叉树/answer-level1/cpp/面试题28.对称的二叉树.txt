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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root,root);
    }
    bool isSymmetric(TreeNode *pNode1,TreeNode *pNode2)
    {
        if(!pNode1&&!pNode2)
            return true;
        if(!pNode1||!pNode2)
            return false;
        if(pNode1->val!=pNode2->val)
            return false;
        return isSymmetric(pNode1->left,pNode2->right)
        &&isSymmetric(pNode1->right,pNode2->left);
    }
};
```
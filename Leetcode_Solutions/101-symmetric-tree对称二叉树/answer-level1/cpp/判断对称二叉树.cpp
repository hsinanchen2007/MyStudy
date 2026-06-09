### 解题思路
在递归里面，深刻理解return的结果是什么，有助于帮助递归。

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
        return isS(root,root);
    }
    bool isS(TreeNode* p, TreeNode* q){
        if(p==nullptr && q== nullptr){
            return true;
        }
        if(p == nullptr || q == nullptr)
            return false;
        if(p->val == q->val){
            return isS(p->left, q->right) && isS(p->right,q->left);
        }
        return false;
    }
};
```
### 解题思路
和100一个思路，注意是判断镜像是否相等

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
    bool isSame(TreeNode* l,TreeNode* r){
        if(!l&&!r) return true;
        else if(!l||!r) return false;
        if(l->val!=r->val)
            return false;
        else 
            return isSame(l->left,r->right)&&isSame(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) 
            return true;
        else 
            return isSame(root->left,root->right);
    }
};
```
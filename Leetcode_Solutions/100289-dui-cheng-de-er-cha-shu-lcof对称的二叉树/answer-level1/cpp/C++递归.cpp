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
    bool jd(TreeNode* a,TreeNode* b){
        if(!a||!b)return a==b;
        if(a->val==b->val)return jd(a->left,b->right)&&jd(b->left,a->right);
        else return 0;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return 1;
        return jd(root->left,root->right);
    }
};
```
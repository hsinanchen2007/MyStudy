### 解题思路
树 的题就是很有框架感，先根后左右，逐一判断，递归

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
        if(root==NULL){
            return true;

        }else{
            return ismirror(root->left,root->right);
        }
    }
    bool ismirror(TreeNode* l,TreeNode* r){
        if(l!=NULL && r!=NULL){
            if(l->val==r->val){
                return ismirror(l->left,r->right)&&ismirror(l->right,r->left);
            }
            else
                return false;
        }
        if(l==NULL&&r==NULL) return true;
        else return false;
    }
};
```
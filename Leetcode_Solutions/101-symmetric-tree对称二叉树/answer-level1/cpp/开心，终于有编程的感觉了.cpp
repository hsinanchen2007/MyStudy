### 解题思路
10分钟写出来了，太开心了，终于有编程的感觉了

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
    bool judge(TreeNode* left,TreeNode* right){
        if(!left&&right)return false;
        else if(left&&!right)return false;
        else if(!left&&!right)return true;
        else{
            if(left->val!=right->val)return false;
            else{
                return judge(left->left,right->right)&&judge(right->left,left->right);
            }
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }else if(!root->left&&root->right){
            return false;
        }else if(root->left&&!root->right){
            return false;
        }else if(!root->left&&!root->right){
            return true;
        }else{
            return judge(root->left,root->right);
        }
    }
};
```
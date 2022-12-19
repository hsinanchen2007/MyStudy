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
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        if(abs(high(root->left)-high(root->right))<=1){
            return isBalanced(root->left)&&isBalanced(root->right);
        }
        else{
            return false;
        }
    }
    int high(TreeNode* root){
        if(!root)return 0;
        else if(!root->left&&!root->right){
            return 1;
        }
        else{
            return max(high(root->left),high(root->right))+1;
        }
    }
};
```
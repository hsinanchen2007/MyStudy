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
        if(root ==NULL){
            return true;
        }
        
        if(abs(treedepth(root->left)-treedepth(root->right))==1||abs(treedepth(root->left)-treedepth(root->right))==0){
            bool p,q;
            p = isBalanced(root->left);
            q = isBalanced(root->right);
            if(p==true &&q==true){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    
    int treedepth(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        int a,b;
        a = treedepth(root->left);
        b = treedepth(root->right);
        return max(a,b)+1; 
    
    }
};
```
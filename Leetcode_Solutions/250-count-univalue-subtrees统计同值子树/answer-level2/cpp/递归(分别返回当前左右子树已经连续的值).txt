### 解题思路


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
    int count=0;
    int countUnivalSubtrees(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return 1; 
        sub(root);
        return count;
    }

    int sub(TreeNode* root){
        if(root==NULL) return INT_MIN+1;
        if(root->left==NULL&&root->right==NULL){
            count++;
            return root->val;
        }
        int l=INT_MIN+1,r=INT_MIN+1;
        if(root->left) l=sub(root->left);
        if(root->right) r=sub(root->right);
        
        //cout<<root->val<<" "<<l<<"--"<<r<<endl;
        //cout<<count<<endl;
        if((root->val==l&&root->val==r)||(l==INT_MIN+1&&root->val==r)||(r==INT_MIN+1&&root->val==l)){
            count++; 
            return root->val;
        }
        else{
            return INT_MIN;
        }
        
        return INT_MIN;
    }
};
```
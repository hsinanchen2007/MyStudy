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
        if(root==NULL) return true;
        int flag=judge(root);
        if(flag<0) return false;
        else return true;
    }

    int judge(TreeNode* root){
        if(root==NULL) return 0;
        int l=judge(root->left)+1;
        int r=judge(root->right)+1;
        //cout<<root->val<<":"<<l<<"-"<<r<<endl;        
        if(l<0||r<0) return INT_MIN;
        if(abs(l-r)<=1){
            return max(l,r);
        }
        else{
            return INT_MIN;
        }
    }
};
```
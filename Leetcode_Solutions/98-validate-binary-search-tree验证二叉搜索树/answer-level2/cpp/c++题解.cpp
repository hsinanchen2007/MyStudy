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
 #include<vector>
 #include<iostream>
class Solution {
public:
    vector<int>  CHILd;
    bool isValidBST(TreeNode* root) {
        return valid(root);
    }
    bool valid(TreeNode *r){
        if(r==NULL) return true;
        
        if(r->left!=NULL){
            if(r->left->val>=r->val) return false;
            CHILd.clear();
            child(r->left->right);

            for(auto c:CHILd){
                
                if(c>=r->val) return false;
            }
        }
        if(r->right!=NULL){
            if(r->right->val<=r->val) return false;
            CHILd.clear();
            child(r->right->left);
            for(auto c:CHILd){

                if(c<=r->val) return false;
            }
        }

        return valid(r->left ) && valid(r->right);
    }
    void child(TreeNode *r){
        if(r==NULL) return;
        CHILd.push_back(r->val);
        child(r->left);
        child(r->right);
    }
    
};
```
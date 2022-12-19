### 解题思路
虽然我代码写得长写的繁琐，但是效率就是高呀：）

### 代码

```cpp
class Solution {
public:
    int l; 
    int min1,min2;
    void haha(TreeNode* root){
        if(isleaf(root))
        return;
        if(root->left->val<min2){
           if(root->left->val<min1){
               min2=min1;
               min1=root->left->val;
           }
           if(root->left->val!=min1)
           min2=root->left->val;
        }
        if((root->right->val)<min2){
            if((root->right->val)<min1){
                min2=min1;
                min1=root->right->val;
            }
            if(root->right->val!=min1)
            min2=root->right->val;
        }
        haha(root->left);
        haha(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        l=root->val;
        min1=l;
        min2=l;
        fii(root);
        if(min1==min2)
        return -1;
        haha(root);
        return min2;
    }
    void fii(TreeNode* root){
        if(isleaf(root))
        return;
        if(root->left->val!=l){
         min1=l>root->left->val?root->left->val:l;
         min2=l<root->left->val?root->left->val:l;
        return;}
        if(root->right->val!=l){
         min1=l>root->right->val?root->right->val:l;
         min2=l<root->right->val?root->right->val:l;
         return;
        }
        fii(root->left);
        fii(root->right);
    }
    bool isleaf(TreeNode* root){
        return root->left==NULL&&root->right==NULL;
    }
};
```
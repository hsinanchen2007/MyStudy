```
class Solution {
public:

    int fun(TreeNode* & root,int result){
       if(root->left==NULL&&root->right==NULL)
            return result+root->val;
        result+=root->val;
        int temp_left=0,temp_right=0;
        if(root->left!=NULL)
            temp_left=fun(root->left,result*10);
        if(root->right!=NULL)
            temp_right=fun(root->right,result*10);
        return  temp_left+temp_right;
    }

    int sumNumbers(TreeNode* root) {
       if(root==NULL)
            return 0;
                int result=0;
        return fun(root,result); 
    }
};
```

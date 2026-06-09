```
class Solution {
public:
    
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL)
            return 0;

        int max = 0;
        
        core(root,max);
        return  max;
    }

    int core(TreeNode* root,int &max)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left = 0;
        int right = 0;

        if(root->left !=NULL)
            left = core(root->left,max) + 1 ;
        if(root->right !=NULL)
            right = core(root->right,max) + 1;
        
        int total = left + right;
        if(total > max)
        {
            max = total;
        }

        return left>right?left:right;
    }
};
```

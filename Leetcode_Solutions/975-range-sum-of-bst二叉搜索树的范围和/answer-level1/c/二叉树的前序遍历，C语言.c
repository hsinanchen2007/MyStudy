```
int rangeSumBST(struct TreeNode* root, int L, int R)
{         
    int sum = 0;
    
    if(root==NULL)
    {
        return 0;
    }
    
    /*前序遍历*/
    if((root->val >= L) && (root->val <= R))
    {
        sum = root->val;
    }
    
     sum += rangeSumBST(root->left, L, R); 
     sum += rangeSumBST(root->right, L, R); 
    return sum;
}
```

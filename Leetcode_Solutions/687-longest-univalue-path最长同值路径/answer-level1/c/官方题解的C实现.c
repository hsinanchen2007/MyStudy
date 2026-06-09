官方的思路说的还算清楚，这里给出C实现的代码，具体描述看官方题解~

注：代码里的left/rightPath对应题解里的left/rightArrow
```
int longestUnivaluePath(struct TreeNode* root){
    
    int seekPath( struct TreeNode *root, int *pAns );

    int ans = 0;
    seekPath( root, &ans );

    return ans;
}

int seekPath( struct TreeNode *root, int *pAns )
{
    if( !root || !root->left && !root->right )
        return 0;
    
    int leftTree, rightTree, leftPath, rightPath;
    leftTree = seekPath( root->left, pAns );
    rightTree = seekPath( root->right, pAns );

    leftPath = ( root->left && root->val == root->left->val ) ? ( 1 + leftTree ) : 0;
    rightPath = ( root->right && root->val == root->right->val ) ? ( 1 + rightTree ): 0;

    if( leftPath + rightPath > *pAns )
        *pAns = leftPath + rightPath;

    return ( leftPath > rightPath ) ? leftPath : rightPath;
}
```

还请大佬优化指正~

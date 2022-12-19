```
/**
*
*整体思路：
*1.遍历二叉树，同时传入当前树的深度level+1，
*2.如果left不为空，继续向下遍历，不为空则递归调用函数，如果为NULL，
*3.则开始遍历右树，不为空则递归调用函数
*4.在函数末尾，存储的深度与当前深度比较，如果大，则更新深度
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
*Function: visiting the tree, and calculating the depth of the tree
*@param: struct TreeNode * root : the tree ready to be visited
*@param: int * count : the parameter of count is used to save the maximun depth of tree
*@param: int level : current depth of tree
*return: void
*/
void Depth( struct TreeNode * root , int * count , int level ){

    //if the left node is not NULL, continuing visiting left of tree
    if( root -> left != NULL ){

        Depth( root -> left , count , level + 1 );

    }

    //if the right node is not NULL, continuing visiting right of tree
    if( root -> right != NULL ){

        Depth( root -> right , count , level + 1 );        

    }

    //if the value of count is lesser than current depth of tree, updating it
    *count = *count > level + 1 ? *count : level + 1;

}

int maxDepth(struct TreeNode* root){

    //if the tree is NULL, return 0
    if( root == NULL ){

        return 0;

    }

    //alloclating memory to save the maximun of depth in the tree 
    int * count = ( int * )malloc( sizeof( int ) * 1 );

    //intializing the memory
    *count = 0;

    Depth( root , count , 0 );

    return *count;

}
```

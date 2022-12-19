```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
*
*整体思路：
*1.遍历二叉树，
*2.判断当前结点是否为NULL，如果不是，遍历左子树left和右子树right
*3.判断当前结点是否为叶子结点，如果是，更新最小深度的值min_depth
*4.返回前，判断min_depth==inf是否成立，是的话，返回0，否则返回min_depth的值
*
*/

#define inf 2147483647

/**
*Function: visiting the binary tree, calclating the minimun of depth in the tree
*@param: struct TreeNode * t : the current node in the tree
*@param: int * min_depth : the minimun of depth in the tree
*@param: int depth : the depth of current node
*
*/
void visitTree( struct TreeNode * t , int * min_depth , int depth ){

    //if current node is NULL, returning void
    if( t == NULL ){
        
        return ; 

    }

    //visiting the left and right child
    visitTree( t -> left , min_depth , depth + 1 );
    visitTree( t -> right , min_depth , depth + 1 );

    //if currenr node is leaf, updating the value of min_depth
    if( t -> left == NULL && t -> right == NULL ){

        *min_depth = *min_depth > depth ? depth : *min_depth;

    }

}

int minDepth( struct TreeNode * root ){

    //the parameter of min_depth used to save the minimun of depth in the tree
    int min_depth = inf;

    visitTree( root , &min_depth , 1 );

    //making sure min_depth is zero when root is NULL
    return min_depth < inf ? min_depth : 0;

}
```

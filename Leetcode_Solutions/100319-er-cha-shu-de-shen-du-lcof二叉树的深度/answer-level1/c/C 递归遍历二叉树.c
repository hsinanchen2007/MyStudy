```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
*
*整体思路：
*1.申请一个变量存储最大深度
*2.如果当前节点为NULL，直接返回void
*3.如果当前深度大于记录的最大深度，更新最大深度
*4.遍历二叉树left子树，同时传入下一个层的深度
*5.遍历二叉树right子树，同时传入下一个层的深度
*6.返回记录的最大深度
*/

/**
*Function: visitng the tree, and calclating the max depth
*@param: struct TreeNode * t : current node in thr binary tree
*@param: int depth : the depth of current node
*@param: int * max_depth : the maximun of depth in the tree
*return: void
*/
void visitTree( struct TreeNode * t , int depth , int * max_depth ){

    //if current node is NULL, returning void
    if( t == NULL ){

        return ;

    }

    //if the depth of current node bigger than max_depth, updating max_depth
    if( depth > *max_depth ){

        *max_depth = depth;

    }

    //visiting the left and right child in the tree
    visitTree( t -> left , depth + 1 , max_depth );
    visitTree( t -> right , depth + 1 , max_depth );

}

int maxDepth( struct TreeNode* root ){

    //the parameter of depth used to save the miximun of depth in binary tree
    int depth = 0;

    //viviting the tree
    visitTree( root , 1 , &depth );

    return depth;

}
```

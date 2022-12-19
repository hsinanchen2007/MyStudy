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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
*
*整体思路：
*1.申请长度为1000的动态内存buffer，同时申请rereturnColumnSizes长度为1000，初始化*returnSize，
*2.初始化returnColumnSizes内存为0，
*3.第一次遍历二叉树，此时buffer存储开关flag=0为关闭状态
*4.如果当前节点为NULL，直接返回，
*5.判断buffer存储开关状态，如果打开，则存入当前t->val
*6.根据深度depth更新returnColumnSizes，*( *( returnColumnSizes + 0 ) + depth )
*7.更新*returnSize为最大深度值
*8.遍历左left子树，
*9.遍历右right子树
*10.遍历returnColumnSizes，为buffer申请具体的一维长度内存，初始化returnColumnSizes对应元素为0
*11.第二次遍历二叉树，buffer存储开关flag=1，
*12.返回buffer
*/

/**
*Function: visiting tree and saving the value of current node to buffer according to flag
*@param: struct TreeNode * t : current node in the tree
*@param: int * returnSize : the dimension of row in buffer
*@param: int ** returnColumnSizes : the length of each row in buffer
*@param: int ** buffer : the memory used to save the value of nodes in the tree
*@param: int depth : the depth of current node
*@param: int flag : determining whether to save the value of current node to buffer
*return: void,
*/
void visitTree( struct TreeNode * t , int * returnSize , int ** returnColumnSizes 
                    , int ** buffer , int depth , int flag ){
    
    //if current node is NULL, returning void
    if( t == NULL ){

        return ;

    }

    //the parameter of col is the value of current element inreturnColumnSizes
    int col = *( *( returnColumnSizes + 0 ) + depth );

    //if flag == 1
    if( flag == 1 ){

        //saving the value of current node to buffer according to depth and col
        *( *( buffer + depth ) + col ) = t -> val;

    } else {

        //recording the maximun of depth in the tree
        *returnSize = *returnSize - 1 > depth ? *returnSize : depth + 1 ;

    }

    //updating the value of element in returnColumnSizes
    *( *( returnColumnSizes + 0 ) + depth ) = ++col;
    //visiting the left child of the tree
    visitTree( t -> left , returnSize , returnColumnSizes , buffer , depth + 1 , flag );
    //visiting the right child of the tree
    visitTree( t -> right , returnSize , returnColumnSizes , buffer , depth + 1 , flag );

}

int ** levelOrder( struct TreeNode * root , int * returnSize , int ** returnColumnSizes ){

    //declaring the parameter of buffer
    int ** buffer;
    //alloclating memory to save the number of nodes in each depth
    *( returnColumnSizes + 0 ) = ( int * )malloc( sizeof( int ) * 1000 );

    //intializing the value of element in returnColumnSizes
    for( int i = 0 ; i < 500 ; i++ ){

        *( *( returnColumnSizes + 0 ) + i ) = 0;
        *( *( returnColumnSizes + 0 ) + i + 500 ) = 0;

    }

    //intializing the value of *returnSize
    *returnSize = 0;

    //visiting the tree first time, trying to calculating the number of nodes in each depth
    visitTree( root , returnSize , returnColumnSizes , buffer , 0 , 0 );
    
    //alloclating memory to save node, the size of memory according to the value of
    buffer = ( int ** )malloc( sizeof( int * ) * ( *returnSize ) );
    //each elements in returnColumnSizes
    for( int i = 0 ; i < *returnSize ; i++ ){

        *( buffer + i ) = 
            ( int * )malloc( sizeof( int ) * ( *( *( returnColumnSizes + 0 ) + i ) ) );
        *( *( returnColumnSizes + 0 ) + i ) = 0;

    }

    //visiting the tree, saving the value of nodes according to depth
    visitTree( root , returnSize , returnColumnSizes , buffer , 0 , 1 );

    return buffer;

}
```

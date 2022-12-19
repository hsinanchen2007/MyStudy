```
/**
*
*整体思路：先序遍历二叉树
*1.如果二叉树为NULL，则返回NULL，否则申请动态内存,一个double类型缓冲区用于存放每层和，一个int缓冲区用于存放
* 每层的数值个数
*2.利用递归遍历二叉树，
*3.将当前node的val存入buffer中，更新num的个数，如果层数为最大层，则更新最大深度
*4.如果root结点的left child不为NULL，则进入递归，同时传入下一层深度
*5.如果root结点的right child不为NULL，则进入递归，同时传入下一层深度
*6.遍历缓冲区，求平均值
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
*Function: visting the tree and calculating total value of each depth
*@param: struct TreeNode * root : the tree ready to ba visited
*@param: double * buffer : the buffer is used to save total value of each depth
*@param: int * num : alloclating memory to save the number of counter in each depth
*@param: int len : the length of buffer and num
*@param: int depth : the depth of current node
*return: void
*/
void visitTree( struct TreeNode * root , double * buffer , int * num , int * len , int depth ){
    
    //calculating total value of each depth
    *( buffer + depth ) += root -> val;
    //updating the number of counter in each depth
    *( num + depth ) += 1;

    //updating the maximun of depth
    if( *len < depth + 1 ){

        *len = depth + 1;

    }

    //if the left child of root is not NULL
    if( root -> left != NULL ){

        visitTree( root -> left , buffer , num , len , depth + 1 );

    }

    //if the right child of root is not NULL
    if( root -> right != NULL ){

        visitTree( root -> right , buffer , num , len , depth + 1 );

    }

}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double * averageOfLevels( struct TreeNode * root , int * returnSize ){
    
    //intializing the length of buffer
    *returnSize = 0;

    //if the root of tree is NULL
    if( root == NULL ){

        return NULL;

    }

    //alloclating memory to save total value of each depth
    double * buffer = ( double * )malloc( sizeof( double ) * 1024 );
    //alloclating memory to count the number of counter in each depth
    int * num = ( int * )malloc( sizeof( int ) * 1024 );

    //intializting each element in buffer and num
    for( int i = 0 ; i < 1024 ; i++ ){

        *( buffer + i ) = 0.0;
        *( num + i ) = 0;

    }

    visitTree( root , buffer , num , returnSize , 0 );

    //calculating the averaging value of each depth
    for( int i = 0 ; i < *returnSize ; i++ ){

        *( buffer + i ) = *( buffer + i ) / *( num + i );

    }

    free( num );

    return buffer;

}
```

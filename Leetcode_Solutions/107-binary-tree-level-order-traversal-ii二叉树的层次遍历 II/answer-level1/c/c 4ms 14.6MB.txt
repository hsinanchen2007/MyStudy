```
/**
*
*整体思路：
*1.采取后续遍历的遍历二叉树
*2.如果left不为NULL，进入下一次递归，否则进入3
*3.如果right不为NULL，进入下一层递归，否则进入4
*4.将当前结点数据存入缓冲区中，记录当前深度
*5.根据深度归并同层数据，逆序存入新的内存中
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


/**
*Function: visiting the tree and saving the value of node and depth to buffer
*@parame: struct TreeNode * root : the tree ready to be visited
*@param: int depth : current depth 
*@param: int * buffer : the memory used to save data
*@param: int * returnSize : the parameter of returnSize is used to save the maximun of depth 
*@param: int * len : the parameter of len is the length of buffer
*return: void
*/
void visitTree( struct TreeNode * root , int depth , int * buffer , int * returnSize , int * len ){

    //if current depth is bigger than restrnSize, replacing it
    if( *returnSize < depth + 1 ){

        *returnSize = depth + 1;

    }

    //if left child is not NULL
    if( root -> left != NULL ){

        visitTree( root -> left , depth + 1 , buffer , returnSize , len );

    }

    //if right child is not NULL
    if( root -> right != NULL ){

        visitTree( root -> right , depth + 1 , buffer , returnSize , len );

    }

    //saving the value and depth of current node to buffer
    *( buffer + *len ) = root -> val;
    *( buffer + *len + 1 ) = depth;
    //updating the pointer in the buffer
    *len += 2;
    

}

int ** levelOrderBottom( struct TreeNode * root , int * returnSize , int ** returnColumnSizes ){

    *returnSize = 0;

    //if root is NULL, return the length os buffer and NULL
    if( root == NULL ){

        
        return NULL;

    }

    //alloclating memory to save the value and depth of tree
    int * buffer = ( int * )malloc( sizeof( int ) * 1024 * 2 );
    //the parameter of len is used to save the length of buffer
    int len = 0;

    visitTree( root , 0 , buffer , returnSize , &len );

    //alloclating new memory to save the data which meets the conditions
    int ** data = ( int ** )malloc( sizeof( int * ) * ( *returnSize ) );
    //alloclating memory to save the length of each array in data
    *( returnColumnSizes + 0 ) = ( int * )malloc( sizeof( int ) * ( *returnSize ) ); 

    //intializing the memory of data and returnColumnSizes
    for( int i = 0 ; i < *returnSize ; i++ ){

        *( *( returnColumnSizes + 0 ) + i ) = 0;
        *( data + i ) = ( int * )malloc( sizeof( int ) * len );

    }

    for( int i = 0 ; i < len ; i += 2 ){

        int row = *returnSize - *( buffer + i + 1 ) - 1;

        //saving the value from the end to the beginning of buffer
        *( *( data + row ) + *( *( returnColumnSizes + 0 ) + row ) ) = *( buffer + i );
        //updating the length of each array in data
        *( *( returnColumnSizes + 0 ) + row ) += 1;

    }

    //free the buffer
    free( buffer );

    return data;

}
```

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
*整体思路：中序遍历
*1.申请动态内存，
*2.中序遍历二叉树并放入缓冲区
*3.遍历缓冲数据，如果后一项减去前一项的差值小于min，则更新min
*4.释放内存，返回min
*/

/**
*Function: visiting the tree and saving the value of nodes to buffer, updating len
*@param: struct TreeNode * t : the tree rady to be visited
*@param: int * buffer : the buffer is used to save the value of nodes
*@param: int * len : the length of buffer
*return: void
*/
void visitTree( struct TreeNode * t , int * buffer , int * len ){

    //if left is not NULL
    if( t -> left != NULL ){

        visitTree( t -> left , buffer , len );

    }

    //saving the value of current node to buffer
    *( buffer + *len ) = t -> val;
    *len += 1;

    //if right is not NULL
    if( t -> right != NULL  ){

        visitTree( t -> right , buffer , len );

    }

}

int minDiffInBST( struct TreeNode * root ){

    //alloclating memory to save the value of nodes 
    int * buffer = ( int * )malloc( sizeof( int ) * 1024 );
    //the parameter of len is the length of buffer
    //the parameter of min is used to save the minimun of the result
    int len = 0 , min = 101;

    visitTree( root , buffer , &len );

    //comparing current element to former element in buffer
    for( int i = 1 ; i < len ; i++ ){

        //if current value is less than min, updating min
        if( *( buffer + i ) - *( buffer + i - 1 ) < min ){

            min = *( buffer + i ) - *( buffer + i - 1 );

        }

    }

    //freeing buffer
    free( buffer );

    return min;

}
```

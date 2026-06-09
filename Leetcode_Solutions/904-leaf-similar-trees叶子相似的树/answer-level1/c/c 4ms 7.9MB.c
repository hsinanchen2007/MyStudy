```
/**
*
*整体思路：
*1.遍历两个二叉树，将leaves数据存入缓冲区中
*2.比较两个缓冲区同索引的数据是否相等，不相等则返回false
*
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
*Funciton: visiting the tree and saving the value of leaf to the buffer, updating the length of buffer
*@param: struct TreeNode * root : the tree ready to be visited
*@param: int * buffer : alloclating memory to save the value of leaf
*@param: int * len : the parameter of len is used to point the current element of buffer
*return: void
*/
void visitTree( struct TreeNode * root , int * buffer , int * len ){

    //if current node is leaf, saving the data to buffer, updating the lenngth of buffer
    if( root -> left == NULL && root -> right == NULL ){

        *( buffer + *len ) = root -> val;
        *len += 1;
        return ; 

    }

    //if current node is not the leaf, continuing visiting
    if( root -> left != NULL ){

        visitTree( root -> left , buffer , len );

    }

    //if current node is not the leaf, continuing visiting
    if( root -> right != NULL ){

        visitTree( root -> right , buffer , len );

    }

}

bool leafSimilar( struct TreeNode * root1 , struct TreeNode * root2 ){

    //if root1 is not equal to root2, return false
    if( ( root1 != NULL && root2 == NULL ) || ( root1 == NULL && root2 != NULL ) ){

        return false;

    } else if( root1 == NULL && root2 == NULL ){

        return true;

    }

    //alloclating memory to save the value of leaves
    int * buffer1 = ( int * )malloc( sizeof( int ) * 1024 );
    int * buffer2 = ( int * )malloc( sizeof( int ) * 1024 );
    //the parameter of len is the length of buffer
    int len1 = 0 , len2 = 0;
    int count = 0;

    //visiting the tree
    visitTree( root1 , buffer1 , &len1 );
    visitTree( root2 , buffer2 , &len2 );

    //if the number of leaves in root1 is not equal to root2, return false
    if( len1 != len2 ){

        free( buffer1 );
        free( buffer2 );
        return false;

    }

    //comparing the elements of buffer1 to that of buffer2
    for( int i = 0 ; i < len1 ; i++ ){

        if( *( buffer1 + i ) != *( buffer2 + i ) ){

            free( buffer1 );
            free( buffer2 );
            return false;

        }

    }

    free( buffer1 );
    free( buffer2 );

    return true;

}
```

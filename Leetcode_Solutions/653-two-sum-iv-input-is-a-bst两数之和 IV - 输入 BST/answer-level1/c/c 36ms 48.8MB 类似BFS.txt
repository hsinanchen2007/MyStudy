```
/**
*
*整体思路：先序遍历
*1.首先遍历二叉树并存储所有节点的值到缓冲区中
*2.利用快速排序，排序整个缓冲区
*3.从前后遍历数组，判断当前两个指针对应的元素和k的大小关系
*   如果left和right的和大于k，则左移right指针
*   如果left和right的和小于k，则右移left指针
*   如果相等，释放缓冲区，return true
*4.如果不满足，释放缓冲区，return false
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

/**
*Fcuntion: visiting the tree and saving the value of nodes to buffer
*@param: struct TreeNode * root : the tree ready to be visited
*@param: int * buffer : alloclating memory to save the value of all nodes
*@param: int * len : the parameter of len is length of buffer
*@param: int k : the value of target
*return: void
*/
void visitTree( struct TreeNode * root , int * buffer , int * len ){

    //saving the value of current node to buffer, and updating the length of buffer 
    *( buffer + *len ) = root -> val;
    *len += 1;

    //if left is not NULL
    if( root -> left != NULL ){

        visitTree( root -> left , buffer , len );

    }

    //if right is not NULL
    if( root -> right != NULL ){

        visitTree( root -> right , buffer , len ); 

    }

}

bool findTarget( struct TreeNode * root , int k ){

    //if the root of tree is NULL or the number of node in the tree less than two, return false
    if( root == NULL || ( root -> left == NULL && root -> right == NULL ) ){

        return false;

    }

    //alloclating memory to save the value of nodes in the tree
    int * buffer = ( int * )malloc( sizeof( int ) * 1024 * 128 );
    //the parameter of len is the length of buffer
    int len = 0;

    visitTree( root , buffer , &len );
    //quick sort
    qsort( buffer , len , sizeof( int ) , cmp );

    //the parameter of left is used to point the left element of buffer,
    //the parameter of right is used to point the right element of buffer,
    int left = 0 , right = len - 1;

    while( left < right ){

        //if the sum of left and right elemnt is bigger than k, moving right to the left element
        if( ( *( buffer + left ) + *( buffer + right ) ) > k ){

            right--;
        
        //if the sum of left and right elemnt is smaller than k, moving left to the right element
        } else if( ( *( buffer + left ) + *( buffer + right ) ) < k ) {

            left++;

        } else {

            //if we can find two elements that meet the condition, return true
            //freeing the buffer
            free( buffer );
            return true;

        }

    }

    //if we can not find two elements that meet the condition, return true
    //freeing the buffer
    free( buffer );
    return false;

}
```

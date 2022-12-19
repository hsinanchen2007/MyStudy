```
/**
*
*整体思路：先序遍历
*1.首先判断二叉树是否为NULL，如果是，return 0,
*2.申请动态内存buffer，buffer用于动态求和，设置计数
*3.首先遍历缓冲区的值，并更新缓冲区的元素加上当前节点的val，并判断是否有等于*sum的，如果有，计数加一
*4.存入当前节点的val到缓冲区中，判断是否等于*sum，如果是，计数加一
*5.如果left不为NULL，递归遍历
*6.如果right不为NULL，递归遍历
*7.移除buffer所有元素中关于当前节点的和
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
*Function: visiting tree and calculating the number of routes whose total value is equal to *sum
*@param: struct TreeNode * root : the tree ready to be visited
*@param: int * buffer : the dynamic buffer is used to save the total value of all kinds of routes
*@param: int len : the parameter of len is the length of buffer that is equaling to the depth of tree
*@param: int * sum : the condition in this question
*@param: int * count : the number of routes whose total value is equal to *sum
*return: void
*/
void visitTree( struct TreeNode * root , int * buffer , int len , int * sum , int * count ){

    //updating the dynamic buffer which is used to save the total value of route
    for( int i = 0 ; i < len ; i++ ){

        if( ( *( buffer + i ) += root -> val ) == *sum ){

            *count += 1;

        }

    }

    //appending current node to a new route 
    if( ( *( buffer + len ) = root -> val ) == *sum ){

        *count += 1;

    }

    //if left is not NULL
    if( root -> left != NULL ){

        visitTree( root -> left , buffer , len + 1 , sum , count );

    }

    //if right is not NULL
    if( root -> right != NULL ){

        visitTree( root -> right , buffer , len + 1 , sum , count );

    }

    //removing current node from dynamic 
    for( int i = 0 ; i < len ; i++ ){

        *( buffer + i ) -= root -> val;

    }

}

int pathSum(struct TreeNode* root, int sum){

    //if the root of the tree is NULL, return 0
    if( root == NULL ){
        
        return 0;

    }
    
    //the parameter of count is used to save the number of route whose taotal value is equaling to *sum
    int count = 0;
    //alloculating memory to save the total value of dynamic route
    int * buffer = ( int * )malloc( sizeof( int ) * 1024 );

    visitTree( root , buffer , 0 , &sum , &count );
    //freeing buffer
    free( buffer );

    return count;

}
```

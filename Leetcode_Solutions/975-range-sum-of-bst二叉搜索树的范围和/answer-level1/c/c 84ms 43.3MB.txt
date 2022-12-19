```
/**
*
*整体思路：中序遍历
*1.进入递归函数
*2.如果节点左树有子节点，则进入子节点递归，
*3.如果无左子节点，则开始判断是否为边界的左侧点，如果是，置位标志位，则开始计算求和
*4.如果为右边界，清空标志位，
*5.判断右子节点是否为空，如果不是，则进入递归
*6.重复2-5否则返回Null
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
*Function: visiting the tree, and calculating the sum between L and R
*@param: struct TreeNode * node : the node ready to visited
*@param: int * buffer : saving the result of the process, and the flag of the span
*@param: int L : the boundary of the left tree
*@param: int R : the boundary of the right tree
*/
 void visitTree( struct TreeNode * node , int * buffer , int L , int R ){
    
    //if left node is not null, visit the left node in the tree
    if( node -> left != NULL ){

        visitTree( node -> left , buffer , L , R );

    }

    //if reach the boundary of the span
    if( node -> val == L ){

        *( buffer + 1 ) = 1;

    }

    if( *( buffer + 1 ) == 1 ){

        *( buffer + 0 ) += node -> val;

    }

    if( node -> val == R ){

         *( buffer + 1 ) = 0;

     }
    
    //if right node is not null, visit the right node in the tree
    if( node -> right != NULL ){

        visitTree( node -> right , buffer , L , R );

    }


 }


int rangeSumBST( struct TreeNode* root , int L , int R ){

    //alloclating memory
    int * buffer = ( int * )malloc( sizeof( int ) * 2 );

    //intializing the memory
    *( buffer + 0 ) = 0;
    *( buffer + 1 ) = 0;

    visitTree( root , buffer , L , R );

    return *( buffer + 0 );

}
```

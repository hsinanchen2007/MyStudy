```
/**
*方法1:时间复杂度O(N)，空间复杂度O(N)，N为额外空间
*整体思路：先序遍历
*1.遍历二叉树，首先将当前节点的数据存入新树中
*2.如果原始tree的left不为NULL，则为新树申请新的空间，递归调用tree的left和新树的right节点
*3.如果原始tree的right不为NULL，则为新树申请新的空间，递归调用tree的right和新树的left节点
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
*Funciton: visiting the tree, and copying the value of root tree to new tree,
*           the direction of the new tree is from right to left
*@param: struct TreeNode * root : the old tree ready to be inverted
*@param: struct TreeNode * root : the new tree is used to save the value of root
*return: void
*/
 /*void invert( struct TreeNode * root , struct TreeNode * t1 ){

     //copying the valur of the root tree to the new tree
     t1 -> val = root -> val;

    //if the left is not NULL in the root, alloclating memory,
    //then, visiting next node
     if( root -> left != NULL ){

         //alloclating memory
         t1 -> right = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );
         //intializing memory
         t1 -> right -> left = NULL;
         t1 -> right -> right = NULL;

         invert( root -> left , t1 -> right );

     }

    //if the right is not NULL in the root, alloclating memory,
    //then, visiting next node
     if( root -> right != NULL ){

         //alloclating memory
         t1 -> left = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );
         //intializing memory
         t1 -> left -> left = NULL;
         t1 -> left -> right = NULL;

         invert( root -> right , t1 -> left );

     }

 }
 */

/**
*方法2:时间复杂度O(N)，空间复杂度O(1)，1个空间用来存放原始根节点
*整体思路：先序遍历
*1.遍历树，
*2.从左树开始，如果当前节点的下一个节点的left或者right不为空，则继续调用递归函数
*3.遍历右树，同2判断条件
*/

/**
*Funciton: inverting the tree by exchanging it's two child left and right
*@param: struct TreeNode * root : the tree ready to be inverted
*return: void
*/
 void exchange( struct TreeNode * root ){

     //if it's child node has left or right child, continuing exchanging
     if( root -> left != NULL && 
        ( root -> left -> left != NULL || root -> left -> right != NULL ) ){

         exchange( root -> left );

     }

    //if it's child node has left or right child, continuing exchanging
     if( root -> right != NULL && 
        ( root -> right -> left != NULL || root -> right -> right != NULL ) ){

         exchange( root -> right );

     }

    //exchaning it's childs no matter one of them is NULL
     struct TreeNode * tmp = root -> left;
     root -> left = root -> right;
     root -> right = tmp;

 }


struct TreeNode * invertTree( struct TreeNode * root ){

    if( root == NULL ){

        return NULL;

    }

    /*---------------------------------------------------
    //this part is another method, it is not a good solution, 
    //alloclating the root of new tree
    struct TreeNode * t = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );
    struct TreeNode * t1 = t;

    //intializing the new tree
    t1 -> val = 0;
    t1 -> left = NULL;
    t1 -> right = NULL;
    

    invert( root , t1 );
    ----------------------------------------------------*/
    

    /*---------------------------------------------------*/
    //this part is the other method
    struct TreeNode * t = root;
    exchange( root );
    

    return t;

}
```

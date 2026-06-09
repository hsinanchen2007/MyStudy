```
/**
*
*整体思路：时间复杂度O(N),空间复杂度O(N)
*1.中序遍历tree，，利用一个指针t暂存new tree的根节点
*2.如果left不为NULL，则递归进入遍历，
*3.将当前结点的val存入新的tree中,保存前一个节点地址，维护当前指针指向下一个right结点
*4.如果right不为NULL，则进入递归遍历，
*5.返回新tree的current(当前)的pointer
*6.暂存的form下一个right指向NULL，是否form后返回t
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * rebuildTree( struct TreeNode * root , struct TreeNode * curr , struct TreeNode * form ){

    //if the left child is not NULL in the tree, continuing visiting
    if( root -> left != NULL ){

        curr = rebuildTree( root -> left , curr , form );

    }

    //saving the value of current node to new tree, then, alloclating new node's memory
    //intializing that memory
    curr -> val = root -> val;
    curr -> right = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );
    form -> right = curr;
    curr = curr -> right;
    curr -> left = curr -> right = NULL;

    //if the left child is not NULL in the tree, continuing visiting
    if( root -> right != NULL ){

        curr = rebuildTree( root -> right , curr , form );

    }

    return curr;

}

struct TreeNode * increasingBST( struct TreeNode * root ){

    //if the root of the tree is NULL, return NULL
    if( root == NULL ){

        return NULL;

    }

    //the parameter of t is used to save the root of the new tree
    struct TreeNode * t = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );
    //the parameter of curr is pointing to current node of new tree
    struct TreeNode * curr = t;
    //the parameter of 
    struct TreeNode * form =( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );

    //intializing the memory
    curr -> right = curr -> left = NULL;
    curr = rebuildTree( root , curr , form );
    //cutting the last node in the new tree
    form -> right -> right = NULL;
    //free the tempary pointer
    free( form );

    return t;

}
```

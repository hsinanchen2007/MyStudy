```
/**
*
*整体思路：先序遍历
*1.利用递归遍历二叉树，
*2.先对当前两个树的结点进行合并
*3.如果t1树的左结点(叶)为null且t2的左结点(叶)不为null，则为t1左子节点(叶)申请动态内存，调用递归函数
*4.如果t1树的右结点(叶)为null且t2的右结点(叶)不为null，则为右t1子节点(叶)申请动态内存，调用递归函数
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
*Function: visiting first and second tree and merging them
*@param: struct TreeNode * t1 : first tree ready to be operated
*@param: struct TreeNode * t2 : second tree ready to be operated
*return: null
*/
void updateTree( struct TreeNode * t1 , struct TreeNode * t2 ){

    //updating node's value in first tree
    t1 -> val = t1 -> val + t2 -> val;

    //we only need to think the situation that second tree next left node is not null
    if( t2 -> left != NULL ){

        //if the left node in first is null, alloclating memory
        if( t1 -> left == NULL ){

            t1 -> left = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );
            //intializing left node
            t1 -> left -> left = NULL;
            t1 -> left -> right = NULL;
            t1 -> left -> val = 0;

        } 

        updateTree( t1 -> left , t2 -> left );

    }

    //we only need to think the situation that second tree next right node is not null
    if( t2 -> right != NULL ){

        //if the right node in first is null, alloclating memory
        if( t1 -> right == NULL ){

            t1 -> right = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );
            //intializing right node
            t1 -> right -> left = NULL;
            t1 -> right -> right = NULL;
            t1 -> right -> val = 0;

        }

        updateTree( t1 -> right , t2 -> right );

    }

}

struct TreeNode * mergeTrees( struct TreeNode * t1 , struct TreeNode * t2 ){

    if( t1 == NULL && t2 != NULL ){

        return t2;

    } else if( t2 == NULL && t1 != NULL ){

        return t1;

    } else if( t1 == NULL && t2 == NULL ){

        return NULL;

    }

    //the parameter of t is used to saving the root of the first tree
    struct TreeNode * t = t1;

    updateTree( t1 , t2 );

    return t;

}
```

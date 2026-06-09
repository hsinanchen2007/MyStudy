```
/**
*
*整体思路：先序遍历(啥遍历都可以)，时间复杂度O(N)，空间复杂度O(1)
*1.判断二叉树是否为NULL或者root无子节点
*2.遍历二叉树，首先传入-1，代表根节点，
*3.如果当前节点为树的叶，且为左子叶，则累加到sum中，
*4.如果left不为NULL，进入遍历，并传入标志位为1的参数
*5.如果right不为NULL，进入遍历，并传入标志位为0的参数
*6.返回结果
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
*Function: visiting the tree and calculating the total value of all the left leaves in the tree
*@param: struct TreeNode * root : the tree ready to be vistied
*@param: int * sum : used to save the toatal value of the left leaves in the tree
*@param: int flag : the flag of current node, -1 : the root of the tree
*           0 : the right leaves, 1 : the left leaves
*return: void 
*/
void visitTree( struct TreeNode * root , int * sum , int flag ){

    //if current node is the left leaves in the tree
    if( flag == 1 && root -> left == NULL && root -> right == NULL ){

        *sum += root -> val;
        return ;

    }

    //if left is not NULL
    if( root -> left != NULL ){

        visitTree( root -> left , sum , 1 );

    }

    //if right is not NULL
    if( root -> right != NULL ){

        visitTree( root -> right , sum , 0 );

    }

}

int sumOfLeftLeaves(struct TreeNode * root ){

    //if the root of the tree is NULL or the number of nodes in the tree only one
    if( root == NULL || ( root -> left == NULL && root -> right == NULL ) ){

        return 0;

    }

    int sum = 0;

    visitTree( root , &sum , -1 );

    return sum;

}
```

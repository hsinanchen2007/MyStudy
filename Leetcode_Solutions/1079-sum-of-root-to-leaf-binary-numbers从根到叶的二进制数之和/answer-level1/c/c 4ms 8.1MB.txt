```
/**
*
*整体思路：
*1.采用递归先序遍历二叉树，构成的十进制数每次整体左移一位
*2.如果left不为NULL，则进入下一层递归，否则进入3
*3.判断right是否为NULL，
*   则进入下一层递归，同时当前结点必不是叶，直接return void;
*   否则进入4
*4.判断left是否为NULL，如果不是，则累加进缓冲区sum中
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
*Function: visiting the tree and calculating the total value of each way to leaves
*@param: struct TreeNode * root : the tree ready to be visited
*@param: int * sum : the parameter of sum is used to save the total value
*@param: int * prio : the parameter of prio is used to save the dynamic value of way to leaves
*return: void
*/
void visitTree( struct TreeNode * root , int * sum , int prio ){

    //moving the integer to left by one bit
    prio = prio * 2 + root -> val;

    //if the left child of current node is not NULL
    if( root -> left != NULL ){

        visitTree( root -> left , sum , &len , prio );

    }

    //if the left child of current node is not NULL, and it must not a leaf, so you can return void here
    if( root -> right != NULL ){

        visitTree( root -> right , sum , &len , prio );
        return ;

    }

    //if crrent node is a leaf, calculating the total value of way to leves
    if( root -> left == NULL ){

        *sum += prio;

    }


}

int sumRootToLeaf(struct TreeNode* root){

    //if the root of tree is NULL, return zero
    if( root == NULL ){

        return 0;

    }

    //if the tree is only one node, return it's val
    if( root -> left == NULL && root -> right == NULL){

        return root -> val;

    }

    //the parameter of sum is used to save the total value of way to leaves
    int sum = 0;

    visitTree( root , &sum ,  0 );

    return sum;

}
```

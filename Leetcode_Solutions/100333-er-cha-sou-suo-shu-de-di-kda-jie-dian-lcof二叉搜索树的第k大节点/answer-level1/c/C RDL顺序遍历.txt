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
*宏定义inf=-2147483647，用于记录最小的31位值
*整体思路：采取RDL遍历，left < parents < right
*1.遍历二叉树，如果当前节点为NULL，返回inf
*2.先遍历right子树，得到返回值rr
*3.如果rr != inf，则直接返回rr
*4.更新*k -= 1，判断*k == 0是否成立，如果是，返回t -> val
*5.后序遍历left子树，得到返回值lr
*6.直接返回lr，无需做判断
*/

#define inf -2147483647

/**
*Function: visiting tree and returning kth maximun in tree
*@param: struct TreeNode * t : current node
*@param: * k : the sequence of current node
*return: int : inf : still not find the kth maximun value in tree ;
*              integer : we have found the kth maximun yet      
*/
int visitTree( struct TreeNode * t , int * k ){

    //if current node is NULL, return inf
    if( t == NULL ){

        return inf;

    }

    //visting the right child of tree
    int rr = visitTree( t -> right , k );

    //if the value of rr does not equal to inf, returning rr now
    if( rr != inf ){

        return rr;

    }

    //updating the value of *k
    *k -= 1;

    //if current node is the kth node in tree, returning it is value
    if( *k == 0 ){

        return t -> val;

    }

    //visting the left child of tree 
    int lr = visitTree( t -> left , k );

    return lr;

}

int kthLargest( struct TreeNode * root , int k ){

    return visitTree( root , &k );

}
```

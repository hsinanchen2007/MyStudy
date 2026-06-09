```
/**
*
*整体思路：中序遍历
*1.先遍历一次二叉树，记录每个结点的和
*2.第二次遍历二叉树，将和更新为减去当前结点的值，
*
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
*Function: visiting the tree and calculating the total value of nodes on the right of current node
*   and updating the value of current node
*@param: int flag1 : determine the operation betweent sum and the value of current node
*@param: struct TreeNode * root : the tree ready to be visited
*@param: int * sum : the total value on the right
*@param: int flag2 : determining whether need to dupdating the value of current node 
*return: void
*/
void visitTree( struct TreeNode * root , int flag1 , int * sum , int flag2 ){

    //if left is not NULL
    if( root -> left != NULL ){

        visitTree( root -> left , flag1 , sum , flag2 );

    }

    *sum += ( root -> val * flag1 );
    root -> val += ( *sum * flag2 );

    //if right is not NULL
    if( root -> right != NULL ){

        visitTree( root -> right , flag1 , sum , flag2 );

    }

}

struct TreeNode * convertBST( struct TreeNode * root ){

    if( root == NULL ){

        return NULL;

    }

    //the parameter of t is used to save the root of tree
    struct TreeNode * t = root;
    //the parameter of sum is used to save the total value of nodes
    int sum = 0;

    //firstly visiting 
    visitTree( root , 1 , &sum , 0 );
    //secondly visiting
    visitTree( root , -1 , &sum , 1 );

    return t;

}


/**方法二：时间复杂度O(N)，空间复杂度O(1)
*
*整体思路：
*1.从right开始遍历，即RDL顺序
*2.用一个额外空间来存储当前结点的right的值
*
*

/**
*Function: visiting the tree and calculating the total value of nodes on the right of current node
*@param: struct TreeNode * root : the tree ready to be visited
*@param: int * sum : the total value on the right
*return: void
*
void visitTree( struct TreeNode * root , int * sum ){

    if( root -> right != NULL ){

        visitTree( root -> right , sum );

    } 

    *sum += root -> val;
    root -> val = *sum;

    if( root -> left != NULL ){

        visitTree( root -> left , sum );

    }

}

struct TreeNode * convertBST( struct TreeNode * root ){

    if( root == NULL ){

        return NULL;

    }

    struct TreeNode * t = root;
    int sum = 0;

    visitTree( root , &sum );

    return t;

}
*/
```

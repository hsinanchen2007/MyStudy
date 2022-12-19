```
/**
*
*整体思路：
*1.自底向上
*
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

int visitTree( struct TreeNode * t , bool * result ){

    int leftDepth = 0 , rightDepth = 0;

    if( t -> left != NULL ){

        leftDepth = visitTree( t -> left , result ) + 1;

    }

    if( t -> right != NULL ){

        rightDepth = visitTree( t -> right , result ) + 1; 

    }

    if( abs( leftDepth - rightDepth ) > 1 ){

        *result = false;

    }

    return leftDepth > rightDepth ? leftDepth : rightDepth;      

}

bool isBalanced(struct TreeNode* root){

    if( root == NULL ){

        return true;

    }

    bool result = true;

    visitTree( root , &result );


    return result;

}
```

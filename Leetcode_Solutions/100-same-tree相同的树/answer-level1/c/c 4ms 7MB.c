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
*
*整体思路：
*1.先序遍历，如果当前结点不全为NULL或者val不相等，返回false,全为NULL，返回NULL，
*2.如果p的left为NULL而q的left不为NULL，返回false
*3.如果p的right为NULL而q的right不为NULL，返回false
*/

bool isSameTree( struct TreeNode * p, struct TreeNode * q){

    if( p == NULL && q == NULL ){

        return true;

    } else if( ( p == NULL && q != NULL ) || ( p != NULL && q == NULL ) 
            || ( p -> val != q -> val )){

        return false;

    }

    if( p -> left != NULL ){

        if( isSameTree( p -> left , q -> left ) == false ){

            return false;

        }

    } else if( q -> left != NULL ){

        return false;

    }

    if( p -> right != NULL ){

        if( isSameTree( p -> right , q -> right ) == false ){

            return false;

        }

    } else if( q -> right != NULL ){

        return false;

    }

    return true;
    

}
```

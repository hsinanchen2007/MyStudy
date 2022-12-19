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
*1.遍历二叉树，
*2.如果left不为NULL，则判断其当前的val和其left是否相同，不同则返回false，判断其递归是否为false，如果是，直接
*  return false
*3.如果right不为NULL，则判断其当前的val和其right是否相同，不同则返回false，判断其递归是否为false，如果是，直接
*  return false
*4.最后返回true
*/

bool isUnivalTree( struct TreeNode * root ){

    //if current node has left child
    if( root -> left != NULL ){

        //comparing the value of current node to the value of it's left child 
        if( root -> val != root -> left -> val ){

            return false;

        }

        //if current node left child does not meet the condition, return false 
        if( isUnivalTree( root -> left ) == false ){

            return false;

        }
        

    }

    //if current node has right child
    if( root -> right != NULL ){

        //comparing the value of current node to the value of it's right child 
        if( root -> val != root -> right -> val ){

            return false;

        }

        //if current node right child does not meet the condition, return false 
        if( isUnivalTree( root -> right ) == false ){

            return false;

        }
        

    }

    //return true
    return true;

}
```

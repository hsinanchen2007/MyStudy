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
* 31 ... 8 7 6 5 4 3 2 1: 4-31位存储当前寻找到x和y的深度，1-3位记录他们父节点
*整体思路：
*1.遍历二叉树，先序遍历，
*2.找到对应节点后，存储其深度与父节点
*
*/

void visitTree( struct TreeNode * t , struct TreeNode * form , int * x , int * y , int depth ){

    //if the velue of current node is equaling the value of assigned x, updating x
    if( t -> val == *x ){

        *x = form -> val + depth * 1000; 

    }

    //if the value of current node is equaling the value of assigned y, updating y
    if( t -> val == *y ){

        *y = form -> val + depth * 1000; 

    }

    //if left is not NULL, visitng the left child of t
    if( t -> left != NULL ){

        visitTree( t -> left , t , x , y , depth + 1 );

    }

    //if right is not NULL, visitng the right child of t
    if( t -> right != NULL ){

        visitTree( t -> right , t , x , y , depth + 1 );

    }

}

bool isCousins( struct TreeNode * root , int x , int y ){

    visitTree( root , root , &x , &y , 0 );

    //making sure x and y in the same depth, and making sure they have different parents 
    if( x % 1000 != y % 1000 && x / 1000 == y / 1000 ){

        return true;

    }

    return false;

}
```

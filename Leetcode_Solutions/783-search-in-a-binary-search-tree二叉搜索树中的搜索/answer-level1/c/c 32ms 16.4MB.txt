```

/**
*
*整体思路：
*1.采用先序遍历，即先判断parent是否满足，如果满足，直接返回当前parent，不满足则返回开始遍历left
*2.对left进行遍历，如果满足不为NULL，则返回当前节点，否则判断right
*3.对right进行遍历，如果满足则返回当前结点，否则最后返回NULL
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
*Function: searching the value in the tree, if can not find it, return NULL, else return root
*@param: struct TreeNode * root : the tree ready to be searched
*@param: int val : the value we had like to searching
*return: struct TreeNode * : root, the value is being confirmed in the tree,
*           NULL : can not find the value in the tree
*/
struct TreeNode * search( struct TreeNode * root , int val ){

    //current node is the root whilch value equals to the parameter of val
    if( root -> val == val ){

        return root;

    }

    //searching the value in the left
    if( root -> left != NULL ){

        //the parameter of t is used to save the result of the process
        struct TreeNode * t = search( root -> left , val );

        //if t is not NULL, which means that we have found the node
        if( t != NULL ){

            return t;

        }

    }

    //searching the value in the right
    if( root -> right != NULL ){

        //the parameter of t is used to save the result of the process
        struct TreeNode * t = search( root -> right , val );
        
        //if t is not NULL, which means that we have found the node
        if( t != NULL ){

            return t;

        }

    }

    return NULL;

}

struct TreeNode * searchBST( struct TreeNode * root , int val ){

    //avoiding judging whether the root is NULL or not in the tree each time
    if( root == NULL ){

        return NULL;

    }

    return search( root , val );

}
```

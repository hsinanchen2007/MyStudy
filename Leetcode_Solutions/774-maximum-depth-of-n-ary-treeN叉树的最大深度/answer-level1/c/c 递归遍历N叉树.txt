```
/**
 * Definition for Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
*
*整体思路：
*1.初始化最大深度max_depth为1
*2.遍历N叉树，判断当前结点是否为leaf叶子结点，如果是，返回NULL
*3.如果不是叶子结点，一次遍历当前结点t的子节点数组，同时深度depth+1
*4.返回最大深度max_depth
*/

void visitTree( struct Node * t , int * max_depth , int depth ){

    //if current node is not NULL
    if( t == NULL ){

        return NULL;

    }

    //updating the value of max_depth if depth bigger than it
    if( depth > *max_depth ){

        *max_depth = depth;

    }

    //visiting the children of current node
    for( int i = 0 ; i < t -> numChildren ; i++ ){

        visitTree( t -> children[ i ] , max_depth , depth + 1 );

    }


}

int * maxDepth( struct Node * root ) {

    //if the root is NULL, returning 0
    if( root == NULL ){

        return 0;

    }

    //the parameter of max_depth used to save the maximun of depth in the N tree
    int max_depth = 1;

    visitTree( root , &max_depth , 1 );

    return max_depth;
    
}
```

```
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node ** children;
 * };
 */

/**
*
*整体思路：
*1.初始化*returnSize = 0
*2.先遍历一次N叉树，计算总的节点数*returnSize，此时存储开关flag=0，即不存储节点数据到buffer中
*3.申请动态buffer长度为*returnSize，初始化*returnSize = 0
*4.第二次遍历N叉树将当前节点数据存入buffer中
*5.返回buffer
*/

/**
*Function: visiting the tree and saving the value of current node to buffer according to flag
*@param: struct Node * t : current node in tree
*@param: int * buffer : the memory used to save the value of nodes in the tree
*@param: int * returnSize : the total number of nodes in the tree
*@param: int flag : determining whether to save the value of nodes to buffer, 1: Yes, 0: No
*return: void
*/
void visitTree( struct Node * t , int * buffer , int * returnSize , int flag ){

    //if current node is leaf
    if( t == NULL ){

        return ;

    }

    //saving the value of current node to buffer
    if( flag == 1 ){

        *( buffer + *returnSize ) = t -> val;

    }

    //updating the value of *returnSize
    *returnSize += 1;

    //visiting the child of current node
    for( int i = 0 ; i < t -> numChildren ; i++ ){

        visitTree( t -> children[ i ] , buffer , returnSize , flag );

    }

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * preorder( struct Node * root , int * returnSize) {

    //intializing the value of *returnSize
    *returnSize = 0;

    //declaring the parameter of buffer
    int * buffer;

    //visiting the tree first time
    visitTree( root , buffer , returnSize , 0 );
    //alloclating memory to save the value of nodes in tree
    buffer = ( int * )malloc( sizeof( int ) * ( *returnSize ) );
    //intializing the value of *returnSize
    *returnSize = 0;
    //visiting the tree second time
    visitTree( root , buffer , returnSize , 1 );

    return buffer;
    
}
```

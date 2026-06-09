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
*1.递归遍历二叉树，第一次递归时，手动令父结点为1,祖父结点为1，根结点和第二层就不会出现异常
*2.判断当前结点是否为NULL，如果是，直接返回void
*3.判断祖父结点是否为偶数，如果是，将当前值加入sum中
*4.遍历左子树，当前结点作为父节点参数，当前结点的父节点作为祖父结点参数传入
*5.遍历右子树，当前结点作为父节点参数，当前结点的父节点作为祖父结点参数传入
*6.返回sum值
*/ 

/**
*Function: calculating the total value of nodes whose grandparent is a even number
*@param: struct TreeNode * t : current node
*@param: int * sum : the total value of nodes which meet the conditions
*@param: int parent : the parent of current node
*@param: int grandParent : the grandparent of current node
*Return: void
*/
void visitTree( struct TreeNode * t , int * sum , int parent  , int grandParent ){

    //if current node is NULL, returning void
    if( t == NULL ){

        return ;

    }

    //if the value of grandparent is a even number, adding the value of current node to sum
    if( grandParent % 2 == 0 ){

        *sum += t -> val;

    }

    //visiting the left and right child,
    visitTree( t -> left , sum , t -> val , parent );
    visitTree( t -> right , sum , t -> val , parent );

} 


int sumEvenGrandparent( struct TreeNode * root ){

    //the parameter of sum used to save the total value of nodes which meet the conditions
    int sum = 0;

    visitTree( root , &sum , 1 , 1 );

    return sum;

}
```

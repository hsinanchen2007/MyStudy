```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 /*
 *
 *整体思路：
 *1.中序遍历数组，同时构建二叉树，保证左边节点小于父节点，右结点大于父节点
 *2.创建递归函数，用于传入左子树与右子树的元素区域
 *3.判断是否为叶结点：如果不是叶子结点，进入步骤4
 *  a)如果mid==left，此时为左叶子结点
 *  b)如果mid+1==right,此时为右叶子结点
 *4.如果不是左叶子结点，创建当前结点的左子结点，左子结点的left和right全部指向NULL，递归创建子结点
 *5.如果不是右叶子结点，创建当前结点的右子结点，左子结点的left和right全部指向NULL，递归创建子结点
 *6.将当前节点的val令为*( nums + mid )
 */

/**
*Function: creating a searching tree according to the sequence of array
*@param: int * nums : the array ready to be used in creating tree
*@param: int left : the border of the left child
*@param: int right : the border of the right child
*@param: struct TreeNode * t : current node ready to be created
*return: void
*/
 void createTree( int * nums , int left , int right , struct TreeNode * t ){
    
    //saving the element in nums to current node
    int mid = ( left + right ) / 2;
    
    //if current node is not left leaf
    if( mid != left ){

        t -> left = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );
        t -> left -> left = t -> left -> right = NULL;

        createTree( nums , left , mid , t -> left );

    }
    
    //if current node is not right leaf
    if( mid + 1 != right ){

        t -> right = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );
        t -> right -> left = t -> right -> right = NULL;

        createTree( nums , mid + 1 , right , t -> right );

    }

    t -> val = *( nums + mid );
     
}

struct TreeNode * sortedArrayToBST( int * nums , int numsSize ){

    if( numsSize == 0 ){

        return NULL;

    }

    //creating the root of the tree
    struct TreeNode * root = ( struct TreeNode * )malloc( sizeof( struct TreeNode ) * 1 );
    root -> left = root -> right = NULL;

    //creating tree
    createTree( nums , 0 , numsSize , root );

    return root;

}
```

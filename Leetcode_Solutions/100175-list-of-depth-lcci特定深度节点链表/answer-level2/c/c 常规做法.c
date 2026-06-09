两个二重指针维护示意图：

![1.png](https://pic.leetcode-cn.com/97183be787a6fad422349428bcc48de8304c2b77199c7d2df5774a4caa0bd21d-1.png)



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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
*
*整体思路：
*1.声明变量buf用于存放每一层结点的链表头，声明curr用于存放链表当前的结点
*2.第一次遍历时，存储开关flag=0,即存储代码关闭，不进行存储操作，仅计算二叉树层数*returnSize
*3.为buf长度为*returnSzie的动态内存，数据类型为struct ListNode *
*4.为curr长度为*returnSzie的动态内存，数据类型为struct ListNode *，并同时初始化内存，保证buf元素
* 指向curr的每个元素，
*5.第二次遍历二叉树，开启存储开关，即flag=1,每次申请一个结点的内存，将结点添加到curr[ depth ]的
*  后面，同时更新curr[ depth ]指针指向的位置
*6.遍历子节点，
*7.为了减少判断的步骤，我们没有对每个链表头结点存入任何数据，所以实际上此时buf[ depth ] -> val
*  全是乱码，我们需要更新头结点，并释放旧的结点
*/

/**
*Function: visiting the binary tree and saving the value of nodes to link according to flag
*@param: struct TreeNode * t : current node in bianry tree
*@param: int depth : the depth of current node
*@param: int * returnSize : the maximun of depth in the bianry tree
*@param: int flag : determining whether to save the value of nodes: 0 : no , 1 : yes
*@param: struct ListNode ** curr : current node of each links
*Return: void
*/
void visitTree( struct TreeNode * t , int depth , int * returnSize , 
                                    int flag , struct ListNode ** curr ){
    
    //if current node is NULL in the binary tree, returning void
    if( t == NULL ){

        return ;

    }

    //saving the value of current node to depthth link
    if( flag == 1 ){

        //alloclating memory to new node in depthth link
        struct ListNode * tmp = ( struct ListNode * )malloc( sizeof( struct ListNode ) * 1 );
        curr[ depth ] -> next = tmp;
        curr[ depth ] = tmp;
        tmp -> val = t -> val;
        tmp -> next = NULL;


    } else {
        
        //only calculating the maximun depth in the binary tree
        *returnSize = *returnSize > depth ? *returnSize : depth;

    }

    //visiting the left and right child int the binary tree
    visitTree( t -> left , depth + 1 , returnSize , flag , curr );
    visitTree( t -> right , depth + 1 , returnSize , flag , curr );

}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode ** listOfDepth( struct TreeNode * tree , int * returnSize ){

    //declearing parameter of buf and curr
    struct ListNode ** buf;
    struct ListNode ** curr;

    //intializing the value of *returnSize
    *returnSize = 0;
    visitTree( tree , 1 , returnSize , 0 , curr );

    //alloclating memory to save the header of each link and current nodes in each link
    buf = ( struct ListNode ** )malloc( sizeof( struct ListNode * ) * ( *returnSize ) );
    curr =( struct ListNode ** )malloc( sizeof( struct ListNode * ) * ( *returnSize ) );

    for( int i = 0 ; i < *returnSize ; i++ ){
        
        //intializing the meomry of buf and curr
        *( curr + i ) = ( struct ListNode * )malloc( sizeof( struct ListNode ) * 1 );
        buf[ i ] = curr[ i ];
        curr[ i ] -> next = NULL;
        curr[ i ] -> val = INT_MIN;

    }

    visitTree( tree , 0 , returnSize , 1 , curr );

    //deleting the header of link, updating the header
    for( int i = 0 ; i < *returnSize ; i++ ){

        struct ListNode * tmp = buf[ i ];
        buf[ i ] = buf[ i ] -> next;
        free( tmp );

    }

    //freeing the memory of curr
    free( curr );
    return buf;

}
```

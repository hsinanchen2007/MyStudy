```
/**
*
*整体思路：先序遍历
*1.如果二叉树为NULL，返回NULL
*2.申请动态内存，s用于动态存储路径，buffer用于所有路径
*3.将当前node的val存入s前需要进行如下步骤
*   如果为0，则直接存入数据0
*   如果不为0，进行如下步骤
*       如果小于0，则添加‘-’,同时将负数变成正整数
*       依次存入数据，翻转当前index到index+k之间的字符
*4.添加箭头
*5.如果left不为NULL，则遍历left,同时传入当前s的偏移量
*6.如果right不为NULL，则遍历right,同时传入当前s的偏移量
*7.如果当前结点为leaf，
*   为buffer申请动态内存，删除动态路径s的最后一个箭头，
*   复制动态路径s到buffer中，更新buffer的当前指针returnSize
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

/**
*Function: visiting tree and saving the route from root to leaves to buffer
*@param: struct TreeNode * root : the tree ready to be visited
*@param: char ** buffer : the memory is used to save all the route
*@param: char * s : the dynamic route
*@param: int * returnSize : pointting current buffer element
*@param: int index : the parameter of index is used to point current elemnt of s
*return: void
*/
void visitTree( struct TreeNode * root , char ** buffer , char * s , int * returnSize , int index ){

    //the parameter of k is uesd to keep the offset of current node in s
    int k = 0 , tmp = root -> val;

    //if the value of current node is 0
    if( tmp == 0 ){

        //continuing to next node
        k = 1;
        *( s + index ) = '0';

    } else {

        //if the value of current node is smaller than 0, 
        if( tmp < 0 ){

            //appending the sign, turning over tmp 
            *( s + index++ ) = '-';
            tmp *= -1;

        }

        //saving the value of current to dynamic route of s
        while( tmp > 0 ){

            *( s + ( index + k++ ) ) = tmp % 10 + 48;
            tmp /= 10; 

        }

        //reversing the character from index to index and k
        for( int i = index , j = index + k - 1 ; i < j ; i++ , j-- ){

            char ch = *( s + i );
            *( s + i ) = *( s + j );
            *( s + j ) = ch;

        }

    }

    //appending the sign of arrow
    *( s + ( index + k++ ) ) = '-';
    *( s + ( index + k++ ) ) = '>';
    *( s + ( index + k ) ) = '\0';

    //if left is not NULL
    if( root -> left != NULL ){

        visitTree( root -> left , buffer , s , returnSize , index + k );

    }

    //if right is not NULL
    if( root -> right != NULL ){

        visitTree( root -> right , buffer , s , returnSize , index + k );

    }

    //if current node is leaf, saving the dynamic route to buffer, updating the pointer in buffer
    if( root -> left == NULL && root -> right == NULL ){

        *( buffer + *returnSize ) = ( char * )malloc( sizeof( char ) * ( index + 5 ) );
        //appending the ending flag of string to s
        *( s + index + k - 2 ) = '\0';
        strcpy( *( buffer + *returnSize ) , s );
        *returnSize += 1;

    }


}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths( struct TreeNode * root , int * returnSize ){

    *returnSize = 0;

    //if the tree is NULL, return NULL
    if( root == NULL ){

        return NULL;

    }

    //alloclating the memory to save all the route
    char ** buffer = ( char ** )malloc( sizeof( char * ) * 128 );
    //alloclating the memory to save dynamic route
    char * s = ( char * )malloc( sizeof( char ) * 1024 );
    //the paramter of len is the offset of s
    int len = 0;

    visitTree( root , buffer , s , returnSize , 0 );

    //free s
    free( s );

    return buffer;

}
```

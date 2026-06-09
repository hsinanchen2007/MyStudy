```
/**
*
*整体思路：先序遍历
*1.首先申请动态内存，
*2.开始遍历二叉树，如果当前节点为NULL，判断其右brother是否为NULL，如果不是，加"()"
*3.如果当前深度不为0，则加左括号'('，将当前节点的val存入字符串中，
*5.开始递归遍历
*6.当前深度不为0，则添加右括号')'
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
*Function: visiting the tree and adding the character of '(' and ')' to string according
*           to right brother is NULL or not
*@param: struct TreeNode * root : the tree ready to visit
*@param: char * s : the buffer is used to save the result of process
*@param: int * len : the parameter of len is the length of s
*@param: int depth : current depth in the tree
*@param: struct TreeNode * form : the parent of current node
*return: void
*/
void visitTree( struct TreeNode * root , char * s , int * len 
                        , int depth , struct TreeNode * form ){

    //if current node is NULL
    if( root == NULL ){

        //if current node has right brother, appending "()" to the end of s
        if( form != NULL && form -> right != NULL ){

            *( s + *len ) = '(';
            *len += 1;
            *( s + *len ) = ')';
            *len += 1;

        }

        return ;

    }

    //if the depth of current node is not zero, appending the character of '(' 
    if( depth != 0 ){

        *( s + *len ) = '(';
        *len += 1;
    
    }

    int k = 0 , tmp = root -> val , i = 0;

    //if tmp is smaller than 0, appending the character of '-'
    if( tmp < 0 ){

        tmp *= -1;
        *( s + *len ) = '-';
        *len += 1;

    } else if( tmp == 0 ){

        //if the value of current node is zero, appending '0'
        *( s + *len ) = '0';
        *len += 1;

    }

    i = *len;

    while( tmp > 0 ){

        *( s + *len ) = tmp % 10 + 48;
        tmp /= 10;
        k++;
        *len += 1;

    }

    int j = *len - 1;

    //reversing the string from the string to the ending of this segment
    while( i < j ){

        char ch = *( s + i );
        *( s + i++ ) = *( s + j );
        *( s + j-- ) = ch;

    }

    //visiting the children of current node if they were existing
    visitTree( root -> left , s , len , depth + 1 , root );
    visitTree( root -> right , s , len , depth + 1 ,  root );

    if( depth != 0 ){

        *( s + *len ) = ')';
        *len += 1;

    }


}

char * tree2str( struct TreeNode * t ){

    //alloclating memory to save the result
    char * buffer = ( char * )malloc( sizeof( char ) * 1024 * 128 );
    //the parameter of len is the length of buffer
    int len = 0;

    visitTree( t , buffer , &len , 0 , t );
    //appending the edning flag of string to buffer
    *( buffer + len ) = '\0';

    return buffer;

}
```

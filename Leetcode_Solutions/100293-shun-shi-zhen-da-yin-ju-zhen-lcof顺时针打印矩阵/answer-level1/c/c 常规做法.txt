```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
*
*整体思路：
*1.初始化*returnSize=0,如果matrix为NULL，直接返回NULL，
*2.申请动态内存buf，长度为 *( matrixColSize + 0 ) * matrixSize,维护*returnSize指向buf 
*2.按环遍历，每一环先从左到右，从上到下，从右到左，从下到上，
*3.每遍历一个元素就对当前元素做标记，标记成INT_MIN，
*4.遍历矩阵，按环进行遍历，满足各自方向的边界条件的同时，且当前元素不为INT_MIN，否则换向或进入下一环：
*   从左到右：边界条件 j < *( matrixColSize + 0 )
*   从上到下：边界条件 i < matrixSize
*   从右到左：边界条件 j >= 0
*   从下到上：边界条件 i > 0
*   内环边界条件：无论从何种方向，当*( *( matrix + i ) + j ) == INT_MIN, 就换向或进入下一环
*5.返回buf
*/

//the minimun of of integer
#define INT_MIN -2147483648

int * spiralOrder(int ** matrix , int matrixSize , int * matrixColSize , int * returnSize ){

    //intializing the pointer of *returnSize
    *returnSize = 0;

    //if matrix is NULL, returning NULL
    if( matrixSize <= 0 ){

        return NULL;

    }

    //alloclating memory to save the final result
    int * buf = ( int * )malloc( sizeof( int ) *( *( matrixColSize + 0 ) * matrixSize ) );
    //the parameter of i is the pointer of row
    //the parameter of j is the pointer of column
    int i = 0 , j = 0;

    //if we do not visit all the elements in matrix yet, continuing visiting
    while( *returnSize < *( matrixColSize + 0 ) * matrixSize ){

        //the direction of visiting from left to right
        for( ; j < *( matrixColSize + i ) && *( *( matrix + i ) + j ) != INT_MIN ; j++ ){

            *( buf + *returnSize ) = *( *( matrix + i ) + j );
            //marking current element
            *( *( matrix + i ) + j ) = INT_MIN;
            //updating the pointer of *returnSize
            *returnSize += 1;

        }

        j--;
        i++;

        //the direction of visiting from up to down
        for( ; i < matrixSize && *( *( matrix + i ) + j ) != INT_MIN ; i++ ){

            *( buf + *returnSize ) = *( *( matrix + i ) + j );
            //marking current element
            *( *( matrix + i ) + j ) = INT_MIN;
            //updating the pointer of *returnSize
            *returnSize += 1;

        }

        i--;
        j--;

        //the direction of visiting from right to left
        for( ; j >= 0 && *( *( matrix + i ) + j ) != INT_MIN ; j-- ){

            *( buf + *returnSize ) = *( *( matrix + i ) + j );
            //marking current element
            *( *( matrix + i ) + j ) = INT_MIN;
            //updating the pointer of *returnSize
            *returnSize += 1;

        }

        i--;
        j++;

        //the direction of visiting down down to up
        for( ; i > 0  && *( *( matrix + i ) + j ) != INT_MIN ; i-- ){

            *( buf + *returnSize ) = *( *( matrix + i ) + j );
            //marking current element
            *( *( matrix + i ) + j ) = INT_MIN;
            //updating the pointer of *returnSize
            *returnSize += 1;

        }

        i++;
        j++;
        
    }

    return buf;

}
```

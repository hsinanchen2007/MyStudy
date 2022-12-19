```
/**
*
*整体思路：（只要比较两个相邻元素即可求得最小差值）
*1.首先对数组进行快速冒泡排序，建立临时缓冲区
*2.比较当前相邻元素差值：
*   如果当前差值比已知min小，则更新最小差值，同时重新维护二维数组指针至起点
*   如果等于当前差值，则存入当前两个数，继续维护指针
*   如果均不是，则进行下一次循环
*3.返回对应的数组
*
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int ** minimumAbsDifference( int * arr , int arrSize , int * returnSize , int ** returnColumnSizes){

    //quick sort 
    qsort( arr , arrSize , sizeof( int ) , cmp );

    //alloclating memorise to save the value 
    int ** buffer = ( int ** )malloc( sizeof( int * ) * arrSize );
    int len = 0 , min = abs( *( arr + 0 ) - *( arr + 1 ) );
    *returnColumnSizes  = ( int * )malloc( sizeof( int ) * arrSize  );

    //we suppose first and second element are the min value
    *( *( returnColumnSizes + 0 ) + len ) = 2;
    *( buffer + len ) = ( int * )malloc( sizeof( int ) * 2 );
    *( *( buffer + len ) + 0 ) = *( arr + 0 );
    *( *( buffer + len ) + 1 ) = *( arr + 0 + 1 );
    len++;

    for( int i = 1 ; i < arrSize - 1 ; i++ ){

        if( min > abs( *( arr + i ) - *( arr + i + 1 ) ) ){

            min = abs( *( arr + i ) - *( arr + i + 1 ) );
            //clearing the pointer
            len = 0;
            *( *( returnColumnSizes + 0 ) + len ) = 2;
            *( buffer + len ) = ( int * )malloc( sizeof( int ) * 2 );
            *( *( buffer + len ) + 0 ) = *( arr + i );
            *( *( buffer + len++ ) + 1 ) = *( arr + i + 1 );

        } else if( min == abs( *( arr + i ) - *( arr + i + 1 ) ) ){

            *( *( returnColumnSizes + 0 ) + len ) = 2;
            *( buffer + len ) = ( int * )malloc( sizeof( int ) * 2 );
            *( *( buffer + len ) + 0 ) = *( arr + i );
            *( *( buffer + len++ ) + 1 ) = *( arr + i + 1 );

        }

    }

    *returnSize = len;

    return buffer;

}
```

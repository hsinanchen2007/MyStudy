```
/**
*
*整体思路：
*1.首先判断是否满足构成新矩阵的条件，如果元素太少，则不满足，按要求返回
*2.分配动态内存等，
*3.遍历数组，分别维护行列指针，满足列数条件时，行数加一
*
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** matrixReshape( int ** nums , int numsSize , int * numsColSize, int r , int c , int * returnSize , int ** returnColumnSizes ){

    *returnColumnSizes = ( int * )malloc( sizeof( int ) * r );

    //if the total element of old matric is less than the new shaping matric,
    //return original matric
    if( ( numsSize * ( *( numsColSize + 0 ) ) ) < ( r * c ) ){

        for( int i = 0 ; i < numsSize ; i++ ){

            *( *( returnColumnSizes + 0 ) + i ) = *( numsColSize + 0 );

        }

        *returnSize = numsSize;
        return nums;

    }

    int row = 0 , col = 0;
    * returnSize = r;
    int ** buffer = ( int ** )malloc( sizeof( int * ) * r );

    for( int i = 0 ; i < numsSize ; i++ ){

        for( int j = 0 ; j < *( numsColSize + i ) ; j++ ){

            //if current element need to save in new line, alloclating new memorise
            if( col == 0 ){

                *( buffer + row ) = ( int * )malloc( sizeof( int ) * c );
                *( *( returnColumnSizes + 0 ) + row ) = c;

            }

            *( *( buffer + row ) + col++ ) = *( *( nums + i ) + j );

            //updating row and col
            if( col == c ){

                row++;
                col = 0;

            }

        }

    }
    
    return buffer;

}
```

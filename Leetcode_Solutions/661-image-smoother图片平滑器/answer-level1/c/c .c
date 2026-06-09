```
/**
*
*整体思路：
*1.申请动态内存用于存放新的数据，初始化相应的内存
*2.遍历数组分别判断八个方向的是否满足，如果是，累加到新的内存中，并记录存入的个数，
*3.根据存入的个数求平均值
*
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** imageSmoother( int ** M , int MSize , int * MColSize , int * returnSize , int ** returnColumnSizes ){

    //intializing memory
    *returnSize = MSize;

    //alloclating memory to save the length of each row and the new data
    *( returnColumnSizes + 0 ) = ( int * )malloc( sizeof( int ) * MSize );
    int ** buffer = ( int ** )malloc( sizeof( int * ) * MSize );

    //visiting the array
    for( int i = 0 ; i < MSize ; i++ ){

        //intializing the length of each row
        *( *( returnColumnSizes + 0 ) + i ) = *( MColSize + i );
        //alloclating memory to save elements in each row
        *( buffer + i ) = ( int * )malloc( sizeof( int ) * ( *( MColSize + i ) ) );

        for( int j = 0 ; j < *( MColSize + i ) ; j++ ){

            //the parameter of count is used to save the number of elements 
            //arround current point
            int count = 1;
            //intializing current point in buffer
            *( *( buffer + i ) + j ) = *( *( M + i ) + j );

            //if former row is not NULL
            if( i - 1 >= 0 ){

                //if former column is not NULL
                if( j - 1 >= 0 ){

                    *( *( buffer + i ) + j ) += *( *( M + i - 1 ) + j - 1 );
                    count++;

                }

                *( *( buffer + i ) + j ) += *( *( M + i - 1 ) + j );
                count++;

                //if next column is not NULL
                if( j + 1 < *( MColSize + i ) ){

                    *( *( buffer + i ) + j ) += *( *( M + i - 1 ) + j + 1 );
                    count++;

                }

            }

            //if next row is not NULL
            if( i + 1 < MSize ){
                
                //if former column is not NULL
                if( j - 1 >= 0 ){

                    *( *( buffer + i ) + j ) += *( *( M + i + 1 ) + j - 1 );
                    count++;

                }

                *( *( buffer + i ) + j ) += *( *( M + i + 1 ) + j );
                count++;

                if( j + 1 < *( MColSize + i ) ){

                    *( *( buffer + i ) + j ) += *( *( M + i + 1 ) + j + 1 );
                    count++;

                }

            }

            //if former column is not NULL
            if( j - 1 >= 0 ){

                *( *( buffer + i ) + j ) += *( *( M + i ) + j - 1 );
                count++;

            }

            //if next column is not NULL
            if( j + 1 < *( MColSize + i ) ){

                *( *( buffer + i ) + j ) += *( *( M + i ) + j + 1 );
                count++;

            }

            //calculating the averaging value of current point
            *( *( buffer + i ) + j ) = *( *( buffer + i ) + j ) / count;

        }

    }

    return buffer;

}
```

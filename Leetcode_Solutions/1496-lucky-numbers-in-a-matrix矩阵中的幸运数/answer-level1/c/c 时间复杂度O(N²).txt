```
/**
*
*整体思路：
*1.申请动态内存row_min用于存放每行最小值，col_max存放每列最大值，
*  buffer存放row_min和col_max相交元素，初始化*returnSize指向0
*2.初始化row_min为每行首元素，col_max每列首元素，
*3.遍历矩阵，如果当前元素>( col_max + j )，更新( col_max + j )
*            如果当前元素>( row_min + i )，更新( row_min + i )
*4.col_max作为外层遍历，row_min作为内层遍历，将相交元素存入buffer，同时更新*returnSize
*5.返回buffer
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * luckyNumbers ( int ** matrix , int matrixSize , int * matrixColSize , int * returnSize){

    //alloclating memory to save the maximun of each column
    int * col_max = ( int * )malloc( sizeof( int ) * ( *( matrixColSize + 0 ) ) );
    //alloclating memory to save the minimun of each row
    int * row_min = ( int * )malloc( sizeof( int ) * matrixSize );
    //allocalting memory to save the elmenet in col_max and row_min at the same time
    int * buffer = ( int *)malloc( sizeof( int ) * matrixSize );

    //intializing the value of *returnSize
    *returnSize = 0;

    
    for( int i = 0 ; i < matrixSize || i < *( matrixColSize + 0 ) ; i++ ){

        //intializing the value of elements in row_min  
        if( i < matrixSize ){

            *( row_min + i ) = *( *( matrix + i ) + 0 );

        }
        
        //intializing the value of elements in col_max
        if( i < *( matrixColSize + 0 ) ){

            *( col_max + i ) = *( *( matrix + 0 ) + i );

        }

    }


    //visiting matrix, updating row_min and col_max
    for( int i = 0 ; i < matrixSize ; i++ ){

        for( int j = 0 ; j < *( matrixColSize + 0 ) ; j++ ){
            
            //if current element is the minimun in current row, updating row_min
            if( *( row_min + i ) > *( *( matrix + i ) + j ) ){

                *( row_min + i ) = *( *( matrix + i ) + j );

            }
            
            //if current element is the maximun in current col, updating col_max
            if( *( col_max + j ) < *( *( matrix + i ) + j ) ){

                *( col_max + j ) = *( *( matrix + i ) + j );

            }

        }

    }

    //saving the element which is included in col_max and row_min at the same
    for( int i = 0 ; i < *( matrixColSize + 0 ) ; i++ ){

        for( int j = 0 ; j < matrixSize ; j++ ){

            if( *( col_max + i ) == *( row_min + j ) ){

                *( buffer + *returnSize ) = *( col_max + i );
                *returnSize += 1;

            }

        }

    }

    return buffer;

}
```

```
/**
*
*整体思路：暴力法
*1.遍历数组
*2.对当前元素处理：
*   前一行同列：如果对应的值大于前一行同列的值，则获取的差值即为表面积
*   后一行同列：如果对应的值大于后一行同列的值，则获取的差值即为表面积
*   前一列同行：如果对应的值大于前一列同行的值，则获取的差值即为表面积
*   后一列同行：如果对应的值大于后一列同行的值，则获取的差值即为表面积
*3.对于边界的，直接计算，不做比较
*
*/

int surfaceArea( int ** grid , int gridSize , int * gridColSize ){

    int square = 0 , count = 0;

    //visiting array
    for( int i = 0 ; i < gridSize ; i++ ){

        for( int j = 0 ; j < *( gridColSize + i ) ; j++ ){

            //if current element is 0, continue next element
            if( *( *( grid + i ) + j ) == 0 ){

                continue;

            }

            count++;

            //former row
            if( i - 1 >= 0 ){

                if( *( *( grid + i ) + j ) > *( *( grid + i - 1 ) + j ) ){

                    square += ( *( *( grid + i ) + j ) - *( *( grid + i - 1 ) + j ) );

                }

            } else if( i == 0 ){

                square += *( *( grid + i ) + j );

            }

            //next row
            if( i + 1 < gridSize ){

                if( *( *( grid + i ) + j ) > *( *( grid + i + 1 ) + j ) ){

                    square += ( *( *( grid + i ) + j ) - *( *( grid + i + 1 ) + j ) );

                }

            } else if( i + 1 == gridSize ){

                square += *( *( grid + i ) + j );

            }

            //next column 
            if( j + 1 < *( gridColSize + i ) ){

                if( *( *( grid + i ) + j ) > *( *( grid + i ) + j + 1 ) ){

                    square += ( *( *( grid + i ) + j ) - *( *( grid + i ) + j + 1 ) );

                }

            } else if( j + 1 == *( gridColSize + i ) ){

                square += *( *( grid + i ) + j );

            }

            //former column
            if( j - 1 >= 0 ){

                if( *( *( grid + i ) + j ) > *( *( grid + i ) + j - 1 ) ){

                    square += ( *( *( grid + i ) + j ) - *( *( grid + i ) + j - 1 ) );

                }

            } else if( j == 0 ){

                square += *( *( grid + i ) + j );

            }
        
        }

    } 

    return square + count * 2;

}
```

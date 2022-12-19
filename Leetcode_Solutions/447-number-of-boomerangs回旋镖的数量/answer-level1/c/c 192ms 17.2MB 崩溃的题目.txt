```
/**
*
*整体思路：
*1.遍历数组，计算当前点与其他所有点的距离大小，
*2.对距离进行排序，遍历距离数组，如果遇到当前值与下一个值相等，计数加一，不相等时，
*   计算当前的排列情况数为：有两个位需要填充，从n个数排列，第一位有n种选择，第二位有n-1种选择
*
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int numberOfBoomerangs( int ** points , int pointsSize , int * pointsColSize ){

    //the parameter of count is the total points of the result
    //the parameter of val is the number of the same number
    int count = 0 , val = 0;
    //the alloclating memory is used to save the distance value
    int * buffer = ( int * )malloc( sizeof( int ) * pointsSize * 2 );

    for( int i = 0 ; i < pointsSize ; i++ ){

        //visting the array, calculating the distance to each point
        for( int j = 0 ; j < pointsSize ; j++ ){

            *( buffer + j ) = pow( *( *( points + i ) + 0 ) - *( *( points + j ) + 0 ) , 2 ) + pow( *( *( points + i ) + 1 ) - *( *( points + j ) + 1 ) , 2 );

        }

        //quick the array
        qsort( buffer , pointsSize , sizeof( int ) , cmp );
        val = 1;

        //calculating the total number of point that have the same distance
        for( int k = 0 ; k < pointsSize - 1 ; k++ ){

            if( *( buffer + k ) == *( buffer + k + 1 ) ){

                val++;
                continue;

            }

            if( val > 1 ){

                count += ( val - 1 ) * val;

            }

            val = 1;

        }
        
        //calculating the last element
        if( val > 1 ){

            count += ( val - 1 ) * val;

        }

    }

    return count;

}
```

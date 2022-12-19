![$QTABMP8HRV54_$FHC`DK\]7.png](https://pic.leetcode-cn.com/f5e7630019dc3adc2c7f644ea850deed5e115aa68a20d3879ce8cc2e94f10851-$QTABMP8HRV54_$FHC%60DK%5D7.png)

```
/**
*时间复杂度O(N*(M+2)),空间复杂度O(M)
*数学规律：
*1.关于xoy投影面积：只要元素不为0，面积加1
*2.关于xoz投影面积：每行数组的最大值相加
*3.关于yoz投影面积：每列元素的最大值相加
*
*/

/**
*
*整体思路：
*1.分配长度为每行长度的动态内存buffer，并假设第一行数组元素*( buffer + j )为每列元素最大值，
*2.遍历行数组，假设第一个元素为当前数组最大值max
*3.如果当前元素为0，继续遍历下一个元素，否则进行如下：
*   面积sum加1
*   如果当前元素大于max，则替换max
*   如果当前元素大于*( buffer + j )则替换
*4.遍历缓冲区数据的同时，累加到面积sum
*/

int projectionArea(int** grid, int gridSize, int* gridColSize){

    //the parameter of sum is used to save the square
    int sum = 0;
    //the allcolating memorise is used to save the column's max value
    int * buffer = ( int * )malloc( sizeof( int ) * ( *( gridColSize + 0 ) ) );

    //supposing the first array's elements is the max value in all column 
    for( int j = 0 ; j < *( gridColSize + 0 ) ; j++ ){

        *( buffer + j ) = *( *( grid + 0 ) + j );

    }
    
    //visiting the elements
    for( int i = 0 ; i < gridSize ; i++ ){

        int max = *( *( grid + i ) + 0 );

        for( int j = 0 ; j < *( gridColSize + i ) ; j++ ){

            //if current element is 0, continue next element
            if( *( *( grid + i ) + j ) == 0 ){

                continue;

            }

            //square adding 1
            sum++;

            //if current elemet's value bigger than max, replacing max by current value
            if( *( *( grid + i ) + j ) > max ){

                max = *( *( grid + i ) + j );

            }

            //if current elemet's value bigger than *( buffer + j ), 
            //replacing max by current value
            if( *( *( grid + i ) + j ) > *( buffer + j ) ){

                *( buffer + j ) = *( *( grid + i ) + j );

            }

        }

        //adding each row's max value to square
        sum += max;

    }

    //adding each column max value to square
    for( int j = 0 ; j < *( gridColSize + 0 ) ; j++ ){

        sum += ( *( buffer + j ) );

    }

    return sum;

}
```

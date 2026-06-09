```
/**
*
*整体思路：
*1.遍历数组
*2.对当前为1的元素进行如下判断，判断前后左右1的个数，则减去对应个数
*
*/

int islandPerimeter(int** grid, int gridSize, int* gridColSize){

    int sum = 0;

    for( int i = 0 ; i < gridSize ; i++ ){

        for( int j = 0 ; j < *( gridColSize + i ) ; j++ ){

            if( *( *( grid + i ) + j ) == 1 ){

                sum += 4;

                //judging the element in the upper
                if( i - 1 >= 0 && *( *( grid + i - 1 ) + j ) == 1){

                    sum -= 1;

                }

                //judging the element in the left
                if( j - 1 >= 0 && *( *( grid + i ) + j - 1 ) == 1){

                    sum -= 1;

                }

                //judging the element in the right
                if( j + 1 < *( gridColSize + i ) && *( *( grid + i ) + j + 1 ) == 1){

                    sum -= 1;

                }

                //judging the element in the bottom
                if( i + 1 < gridSize && *( *( grid + i + 1 ) + j ) == 1){

                    sum -= 1;

                }

            }

        }

    }

    return sum;

}
```

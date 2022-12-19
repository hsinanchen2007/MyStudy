```
/**
*
*整体思路：暴力法
*1.申请动态内存并初始化相应的存储空间，初始化二维数组长度，sum用来记录当前数组和
*2.遍历(1, target/2)的数
*3.如果当前sum<target,继续遍历，
*4.如果sum>target，结束当前以i为首元素的尝试，进入下一趟以i+1为首元素的尝试
*5.如果sum==target,申请相应的空间大小，并依次放入[i, j+1]的数据
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** findContinuousSequence( int target , int * returnSize , int ** returnColumnSizes ){

    //alloclating memory to save all results
    int ** buffer = ( int * )malloc( sizeof( int ) * ( 100 ) );
    //alloclating memory to save the length of every result
    *( returnColumnSizes + 0 ) = ( int * )malloc( sizeof( int ) * ( 100 ) );
    //the parameter of sum used to save the total value of each result
    int sum = 0;
    //intializing the length of buffer
    *returnSize = 0;

    //visitting the number from 1 to target/2
    for( int i = 1 ; i < ( target / 2 + 1 ) ; i++ ){

        //intializing current value of sum
        sum = i;

        //trying the numbers from i to target/2, calculating total value 
        for( int j = 0 ; j < ( target / 2 + 1 ) ; j++ ){

            sum += ( j + i + 1 ); 

            //if the value of sum is bigger than target, continuing next trying
            if( sum > target ){

                break;

            //if the value sum is equaling to target, saving the numbers from i to i+j+1
            } else if( sum == target ){

                *( buffer + *returnSize ) = ( int * )malloc( sizeof( int ) * ( j + 2 ) );
                //updating the length of current array
                *( *( returnColumnSizes + 0 ) + *returnSize ) = j + 2;

                for( int k = i ; k < j + i + 2 ; k++ ){

                    *( *( buffer + *returnSize ) + k - i ) = k;

                }

                //updating the length of buffer
                *returnSize += 1;
                break;

            }

        }

    }

    return buffer;

}
```

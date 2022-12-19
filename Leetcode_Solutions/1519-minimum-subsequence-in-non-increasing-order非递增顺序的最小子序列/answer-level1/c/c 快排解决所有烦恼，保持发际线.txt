```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
*
*整体思路：
*1.题目就是要找出由无序的元素构成的非递增的子数组，这个子数组的和大于其他元素的和
*2.申请长度为numsSize的缓冲区buf，遍历一次数组，计算总的和，
*3.快速排序，
*4.从后往前遍历数组元素，将当前元素放入子数组中，计算子数组的和是否大于其他元素的和，
* 如果是，退出遍历，如果不是，继续下一趟遍历
*5.如果sum2==0，*returnSize = 0，
*6.返回buf
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int * minSubsequence( int * nums , int numsSize , int * returnSize ){

    //the parameter of sum1 used to save the total value of the rest of elements in nums
    //the parameter of sum2 used to save the total value of the subarray
    int sum1 = 0 , sum2 = 0;
    //alloclating memory to save the elements which meet the condition
    int * buf = ( int * )malloc( sizeof( int ) * numsSize );

    //calculating the total value of nums
    for( int i = 0 ; i < numsSize ; i++ ){

        sum1 += *( nums + i );

    }

    //quick sort
    qsort( nums , numsSize , sizeof( int ) , cmp );
    //intializing the value of *returnSize
    *returnSize = 0;

    for( int i = numsSize - 1  ; i >= 0 ; i-- ){

        //updating the value of sum1 and sum2, appending current element to buf
        sum1 -= *( nums + i );
        sum2 += *( nums + i );
        *( buf + *returnSize ) = *( nums + i );
        *returnSize += 1;

        if( sum2 > sum1 ){

            break;

        }

    }

    //if the value of sum2 smaller than zero, returning NULL
    if( sum2 == 0 ){

        *returnSize = 0;

    }

    return buf;

}
```

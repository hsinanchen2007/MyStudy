```
/**
*
*整体思路：
*1.申请动态内存，初始化长度
*2.如果数组长度为0，直接返回
*3.外层循环对应缓冲区buffer的每个下标，
*4.遍历当前[*returnSize, *returnSize + k]之间，找出最大值后，存在*( buffer + *returnSize )中
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * maxSlidingWindow( int * nums , int numsSize , int k , int * returnSize ){

    //alloclating memory to save the result
    int * buffer = ( int * )malloc( sizeof( int ) * ( numsSize - k + 1 ) );
    //intializing the length of buffer
    *returnSize = 0;

    //if the length of nums is zero, returning buffer
    if( numsSize == 0 ){
        
        return buffer;

    }

    //visiting the nums
    for( ; *returnSize < numsSize - k + 1 ; *returnSize += 1 ){

        //intializing current maximun from *returnSize to *returnSize+k is the first element
        *( buffer + *returnSize ) = *( nums + *returnSize );

        for( int j = *returnSize + 1 ; j < *returnSize + k ; j++ ){

            //if the value of current element is the biggest in  subarray
            //from *returnSize to *returnSize+k, updating current eleemnt in buffer  
            if( *( nums + j ) > *( buffer + *returnSize ) ){

                *( buffer + *returnSize ) = *( nums + j );

            }

        }

    }

    return buffer;

}
```

```
/**
*
*整体思路：31 - 4 3 2 1 
*1.遍历并重构nums数组，重构规则：将原数值*1000放在4-31位，1-3位放置当前下标
*2.快速排序重构后的数组，
*3.先访问下标为0的nums数组
*4.遍历1-numsSize的数组，如果出现不同的原数值，则更新计数为当前的i
*5.将count存入缓冲区buffer的*( nums + i ) % 1000 下标位置
*6.循环步骤4
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b ;

}

int * smallerNumbersThanCurrent( int * nums , int numsSize , int * returnSize){

    //the parameter of returnSize if the length of buffer
    *returnSize = numsSize;
    //the parameter of count is used to save the index of fomer different element 
    int count = 0;
    //alloclating memory to save the final result
    int * buffer = ( int * )malloc( sizeof( int ) * numsSize );

    //updating the value of elements in nums
    for( int i = 0 ; i < numsSize ; i++ ){

        *( nums + i ) = *( nums + i ) * 1000 + i;

    }   

    //quick sort
    qsort( nums , numsSize , sizeof( int ) , cmp );

    //updating one element in nums according to nums
    *( buffer + *( nums + 0 ) % 1000 ) = 0;

    //updating the value of elements in buffer deponding on nums
    for( int i = 1 ; i < numsSize ; i++ ){

        //if the value of current elemets in nums is different to fomer one, updating count 
        if( *( nums + i ) / 1000 != *( nums + i - 1 ) / 1000 ){

            count = i;

        }
        
        //updating the value of elements in buffer
        *( buffer + *( nums + i ) % 1000 ) = count; 

    }

    return buffer;

}
```

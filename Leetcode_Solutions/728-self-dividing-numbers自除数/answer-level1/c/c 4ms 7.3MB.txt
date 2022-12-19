```
/**
*
*整体思路：
*1.遍历区间的数，根据区间大小构建一个缓冲区
*2.取出每个位，判断是否符合，如果一个位不符合，则不存储当前的数
*   如果都符合，则存入缓冲区
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * selfDividingNumbers( int left , int right , int * returnSize ){

    //used to save the number that meet the requirement
    int * buffer = ( int * )malloc( sizeof( int ) * ( right - left + 1 ) );
    //the index of the buffer
    int index = 0;

    //visiting the sequence of the number
    for( ; left <= right ; left++ ){

        int tmp = left , flag = 1;

        while( tmp != 0 ){

            //the bit must not 0 or should meet the conditions
            if( ( tmp % 10 == 0 ) || ( left % ( tmp % 10 ) ) != 0 ){

                flag = 0;
                break;

            } 

            tmp /= 10;

        }

        //save the number in the array
        if( flag == 1 ){

            *( buffer + index++ ) = left;

        }

    }

    //return the length of the array
    * returnSize = index;

    return buffer;

}
```

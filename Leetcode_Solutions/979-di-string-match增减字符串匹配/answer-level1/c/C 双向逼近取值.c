```
/**
*
*整体思路：
*1.双指针分别指向0-N序列的首部和尾部
*2.遍历字符数组，如果遇到I时，就从右边指针读取一个值，并指向下一位，下一趟循环
*3.如果为D，则从尾部取值，向前移动指向下一个值
*4.将最后一个数放入缓冲区，并且左右指针终究会相遇
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * diStringMatch( char * S , int * returnSize ){

    //used to save the array's elements
    int * buffer = ( int * )malloc( sizeof( int ) * ( strlen( S ) + 1 ) );
    //pointting to the starting and ending of the sequence
    int left = 0 , right = strlen( S );

    for( int i = 0 ; *( S + i ) != '\0' ; i++ ){

        //judging I or D, then, save the poiner's value in the buffer
        if( *( S + i ) == 'I' ){

            *( buffer + i ) = left;
            left++;
            //if meet this condition, continue to next loop
            continue;

        }

        //used the right's value to save in the buffer
        *( buffer + i ) = right;
        right--;

    }

    //saving the last value, at this time, left must equal to right
    *( buffer + strlen( S ) ) = right;

    //return the length of the buffer, be careful, you should not free the malloc
    *returnSize = strlen( S ) + 1;

    return buffer;

}
```

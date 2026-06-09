```
/**
*
*总体思路：
*1.创建一个数组，从1递增到n/2，依次存入缓冲区中
*2.判断是奇数个还是偶数个后，奇数个时，对中间项加0
*
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero( int n , int * returnSize ){

    int * buffer = ( int * )malloc( sizeof( int ) * ( n + 1 ) );
    int index = 1;

    //save the number in the array one by one
   for( ; index < ( ( n / 2 ) + 1 ) ; index++ ){

       *( buffer + index - 1 ) = -1 * index;
       *( buffer + n - index ) = index;

   }

    //if the number of the array is not odd
   if( n % 2 != 0 ){

       *( buffer + index - 1 ) = 0;

   }

    //return the length of the array
    *returnSize = n;

    return buffer;

}
```

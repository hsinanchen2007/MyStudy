```
/**
*时间复杂度O(2n),空间复杂度O(n)
*整体思路:
*1.申请动态内存,将0从缓冲区右边存入，非0从左边存入，
*2.遍历数组，按1的规则进行，
*3.将缓冲区数据复制到nums数组中，释放缓冲区，维护左右两个指针
*
*/

void moveZeroes( int * nums , int numsSize ){

    //the parameter of right is used to save the value of 0
    //the parameter of right is used to save the value that is not 0
    int right = numsSize - 1 , left = 0;
    //alloclating memorise to save updating array
    int * buffer = ( int * )malloc( sizeof( int ) * numsSize );

    for( int i = 0 ; i < numsSize ; i++ ){

        //if current element is 0
        if( *( nums + i ) != 0 ){

            *( buffer + left++ ) = *( nums + i );

        } else {

            *( buffer + right-- ) = *( nums + i );

        }

    }

    //copying the value of buffer to nums array
    for( int i = 0 ; i < numsSize ; i++ ){

        *( nums + i ) = *( buffer + i );

    }

    free( buffer );

}
```

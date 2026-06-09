```
/**
*
*整体思路：
*1.申请动态内存，
*2.将N化成2进制存入缓冲区中
*3.逆序排序缓冲区
*4.化成十进制输出
*
*/

int bitwiseComplement( int N ){

    int * buffer = ( int * )malloc( sizeof( int ) * 32 );
    int len = 0;

    if( N == 0 ){

        return 1;

    }

    //reversing the bit
    while( N > 0 ){

        *( buffer + len++ ) = ( N % 2 + 1 ) % 2;
        N /= 2;

    } 

    //reversing buffer
    for( int left = 0 , right = len - 1 ; left < right ; left++ , right-- ){

        int tmp = *( buffer + left );
        *( buffer + left ) = *( buffer + right );
        *( buffer + right ) = tmp;

    }

    N = 0;

    for( int i = 0 ; i < len ; i++ ){

        N = N * 2 + *( buffer + i );

    }

    return N;

}
```

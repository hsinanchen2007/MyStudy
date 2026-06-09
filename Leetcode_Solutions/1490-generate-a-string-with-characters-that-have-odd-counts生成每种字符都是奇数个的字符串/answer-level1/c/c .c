```
/**
*
*整体思路：
*1.如果n为奇数，直接全部为'a'，并添加字符串结束标志'\0'
*2.如果n为奇数，前n-1为'a'，最后添加一个字符'b'，并添加字符串结束标志'\0'
*
*
*/

char * generateTheString( int n ){

    //alloclating memory to save the result
    char * s = ( char * )malloc( sizeof( char ) * ( n + 1 ) );

    if( n % 2 == 0 ){

        for( int i = 0 ; i < n - 1 ; i++ ){

            *( s + i ) = 'a';

        }

        *( s + n - 1 ) = 'b';
        *( s + n ) = '\0';

        return s;

    }

    for( int i = 0 ; i < n ; i++ ){

        *( s + i ) = 'a';

    }

    *( s + n ) = '\0';

    return s;

}
```

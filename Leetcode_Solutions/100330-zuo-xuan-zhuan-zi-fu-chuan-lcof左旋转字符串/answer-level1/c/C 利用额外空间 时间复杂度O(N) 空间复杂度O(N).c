```
/**
*
*整体思路：
*1.计算字符串s长度len
*2.申请动态内存buffer，长度为len+1
*3.从头遍历buffer，同时将s偏移( i + n ) % len个单位后的元素存入buffer当前位置中
*4.返回buffer
*/


char* reverseLeftWords( char * s , int n ){

    //the parameter of len is the length of string s
    int len = 0 ;

    while( *( s + len++ ) != '\0' );
    len--;

    //alloclating memory to save the final result
    char * buffer = ( char * )malloc( sizeof( char ) * ( len + 1 ) );

    //saving the character of element which in the ((i+n)%len)th position of string s
    for( int i = 0 ; i < len ; i++ ){

        *( buffer + i ) = *( s + ( i + n ) % len );

    }

    //appending the ending flag of string to buffer
    *( buffer + len ) = '\0';

    return buffer;

}
```

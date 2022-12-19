```
/**
*
*整体思路：
*1.计算字符串s的长度len，计算字符串s的空格数count
*2.申请长度为len+1+count*3的动态缓冲区buffer
*3.遍历字符串s，如果不为' '直接放入buffer中，否则添加“%20”到buffer中
*4.添加'\0'到buffer中
*5.返回buffer
*/

char * replaceSpace( char * s ){

    //the parameter of len is the length of string 
    //the parameter of count used to save the number of spaces in string s
    int len = 0 , count = 0;

    //calculating the length of s and the number of spaces in s
    while( *( s + len ) != 0 ){

        if( *( s + len++ ) == ' ' ){

            count++;

        }

    }

    //alloclating memory to save the final result
    char * buffer = ( char * )malloc( sizeof( char ) * ( len + 1 + count * 3 ) );

    len = 0;

    for( int i = 0 ; *( s + i ) != '\0' ; i++ ){

        //if current element is not space, appending it to buffer
        if( *( s + i ) != ' ' ){

            *( buffer + len++ ) = *( s + i );
            continue;

        }

        //if current element is space, appending "%20" to buffer
        *( buffer + len++ ) = '%';
        *( buffer + len++ ) = '2';
        *( buffer + len++ ) = '0';

    }

    //appending the ending flag of string to buffer
    *( buffer + len ) = '\0';

    return buffer;

}
```

```
/**
*
*整体思路：
*1.申请两个动态内存，
*2.遍历临时动态内存，该内存存有前一次的结果字符串
*3.如果当前字符等于下一个字符，则计数加一，如果不等时，存入字符串中，计算请0
*4.判断最后一个元素，更新缓冲区字符串长度
*
*/

char * countAndSay( int n ){

    //alloclating memory to save the result 
    char * buffer = ( char * )malloc( sizeof( char ) * 1024 * n );
    //alloclating memory to save former buffer's data
    char * tmp = ( char * )malloc( sizeof( char ) * 1024 * n );
    int len = 0;
    //intializing buffer
    *( buffer + len++ ) = '1';
    *( buffer + len ) = '\0';

    //starting calculating
    for( int i = 1 ; i < n ; i++ ){

        //the parameter of count is used to count te number of one type character
        //the parameter of index is used to pointer current buffer's element
        int count = 1 , index = 0;
        //copying buffer to tmp
        strcpy( tmp , buffer );

        for( int j = 0 ; j < len - 1 ; j++ ){

            //if current element is equal to next element, adding the counter
            if( *( tmp + j + 1 ) == *( tmp + j ) ){

                count++;
                continue;

            }

            //else saving current element and it's number to buffer, clearing counter
            while( count > 0 ){

                *( buffer + index++ ) = count % 10 + 48;
                count /= 10;

            }

            *( buffer + index++ ) = *( tmp + j );
            *( buffer + index ) = '\0';
            count = 1;

        }

        //judging the last element of buffer
        while( count > 0 ){

            *( buffer + index++ ) = count % 10 + 48;
            count /= 10;

        }

        //updating the length of buffer
        *( buffer + index++ ) = *( tmp + len - 1 );
        *( buffer + index ) = '\0';
        len = index;

    }

    //free the memory of tmp
    free( tmp );

    return buffer;

}
```

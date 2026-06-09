```
/**
*
*整体思路：
*1.申请动态内存，设置char类型标志位，用于判断首字母是否为元音，如果不是，用于存放改字母
*2.首先对字符串首字母进行判断，再对字符串进行遍历，
*3.遍历的同时，如果不是' '则直接存入当前字符，如果是' '
*  判断标志位是否为1，如果不是，存入标志位数据，
*  根据count加入a，判断下一个字符首部，同时更新标志位，追加' '
*
*/


char * toGoatLatin( char * S ){

    //alloclating memorise to sva the new string
    char * buffer = ( char * )malloc( sizeof( char ) * 1024 * 100 );
    //the parameter of len is current pointer
    //the parameter of count is the number of words
    int len = 0 , count = 0;
    //the parameter of ch is flag flag of a e i o u
    char ch = '1';

    //judging the first element of string
    if( *( S + 0 ) == 'a' || *( S + 0 ) == 'e' || *( S + 0 ) == 'i' 
        || *( S + 0 ) == 'o' || *( S + 0 ) == 'u'
        || *( S + 0 ) == 'A' || *( S + 0 ) == 'E' || *( S + 0 ) == 'I' 
        || *( S + 0 ) == 'O' || *( S + 0 ) == 'U' ){
            
        *( buffer + len++ ) = *( S + 0 );
        ch = '1';

    } else {

        ch = *( S + 0 );

    }

    for( int i = 1 ; *( S + i ) != '\0' ; i++ ){
        
        //if current element is not space, saving it, and, then, continue next loop
        if( *( S + i ) != ' ' ){

            *( buffer + len++ ) = *( S + i );
            continue;

        }

        //if ch is not 1, saving it in the buffer
        if( ch != '1' ){

            *( buffer + len++ ) = ch;
            
        }

        count++;
        //appending "ma" to the end of the word
        *( buffer + len++ ) = 'm';
        *( buffer + len++ ) = 'a';

        //appending 'a' to the end of word according to count
        for( int j = 0 ; j < count ; j++ ){

            *( buffer + len++ ) = 'a';

        }

        //judging next first character of words
        *( buffer + len++ ) = ' ';
        i++;

        if( *( S + i ) == 'a' || *( S + i ) == 'e' || *( S + i ) == 'i' 
            || *( S + i ) == 'o' || *( S + i ) == 'u' 
            || *( S + i ) == 'A' || *( S + i ) == 'E' || *( S + i ) == 'I' 
            || *( S + i ) == 'O' || *( S + i ) == 'U'){
            
            *( buffer + len++ ) = *( S + i );
             ch = '1';

        } else {

            ch = *( S + i );

        }


    }

    //judging the last word, and appending the string "ma", and 'a'
    if( ch != '1' ){

        *( buffer + len++ ) = ch;
            
    }

    count++;
    *( buffer + len++ ) = 'm';
    *( buffer + len++ ) = 'a';

    for( int j = 0 ; j < count ; j++ ){

        *( buffer + len++ ) = 'a';

    }

    *( buffer + len ) ='\0';

    return buffer;

}
```

```

/**
*
*整体思路：
*1.建立结构体strNode的数组，用于存放每个单词以及对应的长度信息
*2.通过快排，重新按单词长度排序字符串数组
*3.遍历排序后的数组，确定当前单词是否为压缩后的字符串的子串，如果是，则进行压缩后，添加#，更新偏移index
4.释放缓冲区，返回index
*/

typedef struct {

    char * word;
    int len;

} strNode ;

int cmp( const void * a , const void * b ){

    strNode n1 = *( strNode * )a;
    strNode n2 = *( strNode * )b;

    return n2.len - n1.len;

}

int minimumLengthEncoding( char ** words , int wordsSize ){

    //alloclating memory to save the length of the words
    strNode * str = ( strNode * )malloc( sizeof( strNode ) * wordsSize );
    //the parameter of leb is the length of words
    int len = 0;
    
    //calculating the length of words and the total length of words
    for( int i = 0 ; i < wordsSize ; i++ ){

        str[ i ].len = strlen( *( words + i ) );
        str[ i ].word = *( words + i );
        len += str[ i ].len; 

    }   

    //alloclating meomry to save the final result
    char * buffer = ( char * )malloc( sizeof( char ) * ( len + wordsSize + 1 ) );

    //quick sort according to the length of word
    qsort( str , wordsSize , sizeof( str[ 0 ] ) , cmp );
    *( buffer + 0 ) = '\0';
    len = 0;

    //visiting the words
    for( int i = 0 ; i < wordsSize ; i++ ){

        char * tmp = strstr( buffer, str[ i ].word );

        if ( tmp == NULL || tmp[ str[ i ].len ] != '#' ) {

            len += sprintf( buffer + len, "%s#", str[ i ].word );

        }

    }

    free( str );
    free( buffer );
    return len;

}
```

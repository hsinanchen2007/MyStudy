```
/**
*
*整体思路：
*1.将当前的单词存入缓冲区中，与单词表进行对比，确定是否出现，如果出现，则计数加1，
*2.同样对B字符串进行相同操作，利用一个计数动态内存记录出现次数
*3.删除计数不为1的单词
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** uncommonFromSentences( char * A , char * B , int * returnSize ){

    //alloclating memorise used to save the words
    char ** buffer = ( char ** )malloc( sizeof( char * ) * 100 );
    //saving current word
    char * s = ( char * )malloc( sizeof( char ) * 100 );
    //saving the number of the word in the string A and B
    int * count = ( int * )malloc( sizeof( int ) * 100 );
    //the parameter of len is length of buffer, the parameter is current pointer of s
    int len = 0 , index = 0;

    //appending the word in string A to buffer, and count the count
    for( int i = 0 ; *( A + i ) != '\0' ; i++ ){

        //one word
        if( *( A + i ) != ' ' ){

            *( s + index++ ) = *( A + i );
            continue;

        }

        //making sure appending the ending flag of the string
        *( s + index ) = '\0';
        index = 0;

        int flag = 0;

        //visting the buffer to confirm if it have exsit in the buffer
        for( int j = 0 ; j < len ; j++ ){

            if( strcmp( *( buffer + j ) , s ) == 0 ){

                *( count + j ) += 1;
                flag = 1;
                break;

            }

        }

        if( flag == 1 ){

            continue;

        }

        *( buffer + len ) = ( char * )malloc( sizeof( char ) * 50 );
        *( count + len ) = 1;
        strcpy( *( buffer + len++ ) , s );

    }

    //judging the last word, and appanding to the buffer or updating the number of count
    *( s + index ) = '\0';
    int flag = 0;

    for( int j = 0 ; j < len ; j++ ){

        if( strcmp( *( buffer + j ) , s ) == 0 ){

            *( count + j ) += 1;
            flag = 1;
            break;

        }

    }

    if( flag == 0 ){

        *( s + index ) = '\0';
        *( buffer + len ) = ( char * )malloc( sizeof( char ) * 50 );
        *( count + len ) = 1;
        strcpy( *( buffer + len++ ) , s );

    }

    index = 0;

    for( int i = 0 ; *( B + i ) != '\0' ; i++ ){

        if( *( B + i ) != ' ' ){

            *( s + index++ ) = *( B + i );
            continue;

        }

        *( s + index ) = '\0';
        index = 0;

        int flag = 0;

        for( int j = 0 ; j < len ; j++ ){

            if( strcmp( *( buffer + j ) , s ) == 0 ){

                *( count + j ) += 1;
                flag = 1;
                break;

            }

        }

        if( flag == 1 ){

            continue;

        }

        *( buffer + len ) = ( char * )malloc( sizeof( char ) * 50 );
        *( count + len ) = 1;
        strcpy( *( buffer + len++ ) , s );

    }

    *( s + index ) = '\0';
    flag = 0;

    for( int j = 0 ; j < len ; j++ ){

        if( strcmp( *( buffer + j ) , s ) == 0 ){

            *( count + j ) += 1;
            flag = 1;
            break;

        }

    }

    if( flag == 0 ){

        *( s + index ) = '\0';
        *( buffer + len ) = ( char * )malloc( sizeof( char ) * 50 );
        *( count + len ) = 1;
        strcpy( *( buffer + len++ ) , s );

    }

    index = 0;

    //updating the buffer according to the number of count
    for( int i = 0 ; i < len ; i++ ){

        if( *( count + i ) == 1 ){

            strcpy( s , *( buffer + i ) );
            strcpy( *( buffer + index ) , s );
            index++;

        }

    }

    *returnSize = index;

    return buffer;

}
```

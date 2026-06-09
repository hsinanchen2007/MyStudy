```
/**
*
*整体思路：
*1.遍历text字符串，将单词依次放入buffer缓冲区中，
*2.滑动窗口，每次将i和i+1字符串与first和second字符串比较，如果相等，则存入buffer中，
*  同时维护字符串数组长度指针
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findOcurrences( char * text , char * first , char * second , int * returnSize ){

    //alloclating memorise to save words and third word
    char ** buffer = ( char ** )malloc( sizeof( char * ) * 100 );
    //alloclating memorise to save word's string
    *( buffer + 0 ) = ( char * )malloc( sizeof( char ) * 50 );
    //the parameter of len is the length of buffer,
    //the parameter of index is current element pointer
    int len = 0 , index = 0;

    //saving words that is in the text string to buffer 
    for( int i = 0 ; *( text + i ) != '\0' ; i++ ){

        if( *( text + i ) != ' ' ){

            //copying current character to buffer
            *( *( buffer + len ) + index++ ) = *( text + i );
            continue;

        }

        //remembering append the ending flag of string to word
        *( *( buffer + len ) + index ) = '\0';
        //intializing the current pointer
        index = 0;
        //updating the length of buffer
        len++;
        //alloclating memorise to save word's string
        *( buffer + len ) = ( char * )malloc( sizeof( char ) * 50 );

    }

    //appending the last word to buffer
    *( *( buffer + len ) + index ) = '\0';
    len++;
    index = 0;

    //if current words less than 3, return NULL
    if( len < 3 ){

        return NULL;

    }

    //comparing to the parameter of first and second, and, then, saving the third word to buffer
    for( int i = 0 ; i < len - 2 ; i++ ){

        if( strcmp( *( buffer + i ) , first ) == 0 && strcmp( *( buffer + i + 1 ) , second ) == 0 ){

            strcpy( *( buffer + index ) , *( buffer + i + 2 ) );
            index++;

        }

    }

    *returnSize = index;

    return buffer;

}
```

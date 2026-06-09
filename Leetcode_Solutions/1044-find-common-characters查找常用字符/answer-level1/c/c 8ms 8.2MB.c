```
/**
*
*整体思路:
*注意：只要以第一个字符串作为最原始参照即可
*1.取第一个字符串的一个字符，与其他字符串每个字符做比较，
*   比较的同时，只要查找到相同字符，即可返回对应的标志位，
*   同时，对于满足条件的，置位即可，置位的目的主要是方便后续
*   删除已经使用过的字符，防止重复计数
*2.如果该字符在每个字符串中均出现，则对缓冲区存放的下标进行清空操作
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars( char ** A , int ASize , int * returnSize ){

    //the parameter of len is the length of the first string in the A
    int len = strlen( *( A + 0 ) ) , move = 0 ;
    int i = 1, j = 0;
    //the allocalating memorise is used to save the result characters
    char ** buffer = ( char ** )malloc( sizeof( char * ) * len );

    //the first string in the A used to be compared
    for( int k = 0 ; k < len ; k++ ){

        int flag = 1;
        //used to save the index of characters that meeting the condition 
        int * index = ( int * )malloc( sizeof( int ) * ( ASize - 1 ) );

        for( i = 1 ; i < ASize ; i++ ){

            int tt = 0;
            
            for( j = 0 ; *( *( A + i ) + j ) != '\0' ; j++ ){

                *( index + i - 1 ) = -1;

                if( *( *( A + 0 ) + k ) == *( *( A + i ) + j ) ){

                    //remembering the index
                    *( index + i - 1 ) = j;
                    tt = 1;
                    break;

                }

            }

            if( tt == 1 ){

                continue;

            }

            flag = 0;
            break;

        }

        //if the character is in all string
        if( flag == 1 ){

            //clearing the characters that in all string
            for( int m = 0 ; m < ASize - 1 ; m++ ){

                *( *( A + m + 1 ) + *( index + m ) ) = '1';

            }
            
            //saving the characters in the memorise
            *( buffer + move ) = malloc( sizeof( char ) * 2 );
            *( *( buffer + move ) + 0 ) = *( *( A + 0 ) + k );
            *( *( buffer + move ) + 1 ) = '\0';
            move++;

        }

    }

    *returnSize = move;

    return buffer;

}
```

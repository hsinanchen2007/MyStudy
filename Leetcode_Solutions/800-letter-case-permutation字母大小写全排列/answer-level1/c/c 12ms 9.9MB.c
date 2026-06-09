```
/**
*
*整体思路：
*1.大概思路就是如官方解答的：
*   当 S = "abc" 时，考虑字母 "a", "b", "c"，初始令 ans = [""]，依次更新 ans = ["a", "A"]， ans = ["ab", "Ab",*   "aB", "AB"]， ans = ["abc", "Abc", "aBc", "ABc", "abC", "AbC", "aBC", "ABC"]。
*2.如果是0-9字符，则只加入即可
*3.具体操作细节：先对原字符串进行长度计算，同时计算a-z或A-Z的个数，便于申请动态内存，同时初始化一个
*  字符数组为'\0'
*4.将当前的S字符存入已有的字符串中，对新申请的动态内存进行复制，同时根据原字符打大小写，决定是进行+-32，
*  由标志位upper决定，如果为小写，upper = -1,反之则为1 
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCasePermutation( char * S , int * returnSize){

    //the parameter of len is the length of the buffer,
    //the parameter length is the length of S
    //the parameter count is used to count the number of English characters
    int len = 1 , length = 0 , count = 0 ;

    //callculating the length of S, and the number of English
    for( ; *( S + length ) != '\0' ; length++ ){

        if( ( *( S + length ) >= 'a' && *( S + length ) <= 'z' ) 
            || ( *( S + length ) >= 'A' && *( S + length ) <= 'Z' ) ){

                count++;

        }

    }

    char ** buffer = ( char ** )malloc( sizeof( char * ) * ( pow( 2 , count ) ) );
    *( buffer + 0 ) = ( char * )malloc( sizeof( char ) * ( length + 1 ) );
    *( *( buffer + 0 ) + 0 ) = '\0';

    for( int j = 0 ; j < length ; j++ ){
        
        //if current element is 0-9, saving in the buffer, and, continue
        if ( *( S + j ) >= '0' && *( S + j ) <= '9' ){

            int i = 0;

            for(  ; i < len ; i++ ){

                *( *( buffer + i ) + j ) = *( S + j );
                //making sure you have appended the ending flag of the string
                *( *( buffer + i ) + j + 1 ) = '\0';

            }

            continue;

        }

        //the parameter of upper is used to mark current is upper or not
        int upper = 1;

        if( *( S + j ) >= 'a' && *( S + j ) <= 'z' ){

            upper = -1;

        }

        int i = 0;
        
        //each time when saving current element in the buffer, alloclating new memorise, and copy current
        //string to new memorise, then, changing the upper
        for(  ; i < len ; i++ ){
            
            *( *( buffer + i ) + j ) = *( S + j );
            //making sure you have appended the ending flag of the string
            *( *( buffer + i ) + j + 1 ) = '\0';
            *( buffer + len + i ) = ( char * )malloc( sizeof( char ) * ( length + 1 ) );
            strcpy( *( buffer + len + i ) , *( buffer + i ) );
            *( *( buffer + len + i ) + j ) += ( 32 * upper );
            //making sure you have appended the ending flag of the string
            *( *( buffer + i + len ) + j + 1 ) = '\0';

        }

        //the length of buffer is twice bigger than before
        len *= 2;
        

    }

    *returnSize = len;

    return buffer;

}
```

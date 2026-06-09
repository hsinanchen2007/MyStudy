```
/**
*
*总体思路：
*1.先判断每个子字符串首字母在表中第几行
*2.后续遍历子字符串时，仅在相同的行中对比，如果存在，则返回1，否则返回0
*3.根据返回结果，更新字符串
*
*/


/**
*Function: checking the character whether in the same row or return the number of row
*@param : char ch : the character ready to be checked
*@param : int row : -1 : the first character in the string, return the row in the table
*                 : 0 - 3 : the row of the string that includes the character 
*return : int : the result of the checking process
*              0 : failed, 1 : sucessed
*              0 - 3 : the row of the first character that in the substring         
*/
int checkWords( char ch , int row ){

    //the table ready to be searched
    char buffer[  ][ 11 ] = { "qwertyuiop" , "asdfghjkl" , "zxcvbnm" };

    //if the character is in the first position of the substring, return the row in the table
    if( row == -1 ){

        for( int i = 0 ; i < 3 ; i++ ){

            for( int j = 0 ; *( *( buffer + i ) + j ) != '\0' ; j++ ){
                
                //make sure the upper and small can be checked
                if( *( *( buffer + i ) + j ) == ch || ( *( *( buffer + i ) + j ) - 32 ) == ch ){

                    return i;

                }

            }

        }

    } else {

        for( int j = 0  ; *( *( buffer + row ) + j ) != '\0' ; j++ ){

            if( *( *( buffer + row ) + j ) == ch || ( *( *( buffer + row ) + j ) - 32 ) == ch ){

                //if the character in the same row, return 1
                return 1;

            }

        }

    }

    return 0;

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char ** words, int wordsSize, int* returnSize){
    
    //the parammeter of index is used to point the updataing of the array
    int index = 0 , row = 0;

    for( int i = 0 ; i < wordsSize ; i++ ){

        row = checkWords( *( *( words + i ) + 0 ) , -1 );

        for( int j = 1 ; *( *( words + i ) +j ) != '\0' ; j++){

            //if the character is not in the same row, stop checking
            if( checkWords( *( *( words + i ) + j ) , row ) == 0 ){

                row = -1;
                break;

            }

        }

        //if the character is not in the same row, continue next substring
        if( row == -1 ){

            continue;

        }

        //updating the array
        *( words + index++ ) = *( words + i );

    }

    *returnSize = index;

    return words;
    
}
```

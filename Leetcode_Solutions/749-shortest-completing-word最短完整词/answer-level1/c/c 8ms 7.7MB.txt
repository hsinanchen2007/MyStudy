```
/**
*
*整体思路：
*1.首先去除licensePlate中的所有非字母字符，大写转换成小写，时间复杂度O(N)，空间复杂度O(1)
*2.遍历words，将每个字符与licensePlate比较，如果全部存在words字符串中，保留当前下标，
*3.重复2，知道遍历完成
*4.返回最小长度的字符串
*
*/

char * shortestCompletingWord( char * licensePlate , char ** words , int wordsSize){

    //alloclating memory to save current word's string
    char * s = ( char * )malloc( sizeof( char ) * 16 );
    //the parameter of index is the length of licensePlate string
    //the parameter of min_index is used to save the shorest string of word's index
    int index = 0 , min_index = -1;

    //updating ;icensePlate, deleting other character and changing the upper
    for( int i = 0 ; *( licensePlate + i ) != 0 ; i++ ){

        if( *( licensePlate + i ) <= 'z' && *( licensePlate + i ) >= 'a' ){

            *( licensePlate + index++ ) = *( licensePlate + i );

        } else if( *( licensePlate + i ) <= 'Z' && *( licensePlate + i ) >= 'A' ){

            *( licensePlate + index++ ) = ( *( licensePlate + i ) ) + 32;

        }

    }

    //appending the ending flag of the string
    *( licensePlate + index ) = '\0';

    //visiting word's string
    for( int i = 0 ; i < wordsSize ; i++ ){

        //the parameter of flag is used to mark current string whether it meet the condition
        char flag = '1';
        strcpy( s , *( words + i ) );

        for( int k = 0 ; k < index ; k++ ){
                
            char con = '0';

            //comparing licensePlate's character to current string's character one by one
            for( int j = 0 ; *( s + j ) != '\0' ; j++ ){

                //deleting current character, avoiding using aganin
                if( *( s + j ) == *( licensePlate + k ) ){

                    *( s + j ) = '.';
                    con = '1';
                    break;

                }

            }

            if( con == '0' ){
                    
                flag = '0';
                break;

            }

        }

        //if current string meet condition, making sure it is the shorest string, it is, replace
        //the index
        if( flag == '1' && min_index == -1 ){

            min_index = i;
            continue;

        } else if( flag == '1' && ( strlen( *( words + i ) ) < strlen( *( words + min_index ) ) ) ){

            min_index = i;

        }

    }

    return  *( words + min_index );

}
```

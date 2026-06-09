```
/**
*
*整体思路：查表法，
*1.按ASCII码表字母顺序映射在字典里面的位置，
*2.遍历二维数组，最外层循环为单词，最内层循环为当前单词和下一个单词的字符比较
*   三种情况：
*   a.如果大于，直接返回false
*   b.如果等于，进行下一次比较，直到某个单词结束还未比较出结果，则继续比较，长度长的默认大于段的
*   c.如果比较出结果，满足条件，标志位置'1'
*3.循环2步骤，直到不满足条件
*
*/

bool isAlienSorted(char ** words, int wordsSize, char * order){

    //alloclating memory to save the new table in the order's position
    int * buffer = ( int * )malloc( sizeof( int ) * 26 );
    
    //creating the diviational table
    for( int i = 0 ; i < 26 ; i++ ){

        *( buffer + i ) = -1;

        for( int j = 0 ; *( order + j ) != '\0' ; j++ ){

            if( ( "abcdefghijklmnopqrstuvwxyz" )[ i ] == *( order + j ) ){

                *( buffer + i ) = j;
                break;

            }

        }

    }

    //visiting the words
    for( int i = 0 ; i < wordsSize - 1 ; i++ ){

        int j = 0;
        char flag = '0';

        //comparing current word to next one
        for(  ; *( *( words + i ) + j ) !='\0' && *( *( words + i + 1 ) + j ) !='\0'; j++ ){

            //if current word bigger than next one, return false
            if( *( buffer + ( *( *( words + i ) + j ) - 97 ) ) 
                > *( buffer + ( *( *( words + i + 1 ) + j ) - 97 ) ) ){

                return false;    

            } else if ( *( buffer + ( *( *( words + i ) + j ) - 97 ) ) 
                == *( buffer + ( *( *( words + i + 1 ) + j ) - 97 ) ) ) {
                //if current word equal to next one, continue next character
                continue;

            }

            //if current word samller than next one, continue next word
            flag = '1';
            break;
            
        }

        //if one word shorter than the other one, comparing their ending character
        if( flag == '0' && ( *( *( words + i ) + j ) > *( *( words + i + 1 ) + j ) ) ){

            return false;

        }

    }

    //all words meet the condition, return true
    return true;

}
```

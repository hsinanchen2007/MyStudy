```
/**
*
*整体思路：
*1.遍历数组，同时每遍历一个元素时，就遍历一次字符表，
*2.存在时，对缓冲区字符表清空，并记录后返回，
*3.如果一个字符不存在，则证明该单词未掌握，继续检查下一个word，
*4.一个单词检查完毕与否，将移动的位数与单词长度比较，如果相等，则证明掌握，
*  掌握数增加
*
*/

int countCharacters( char ** words , int wordsSize , char * chars ){

    int sum = 0 , index = 0 , len = strlen( chars );
    //the alloclating memorise is used to save the chars
    char * s = ( char * )malloc( sizeof( char ) * ( len + 1 ) );

    for( int i = 0 ; i < wordsSize ; i++ ){

        //calculating the length of the word
        int end = strlen( *( words + i ) );
        index = 0;
        //copy chars to the temperary memorise
        strcpy( s , chars );

        //if the length of the word is shorter than chars, continue next word
        if( len < end ){

            continue;

        }

        for( int j = 0 ; j < end ; j++ ){

            int flag = 0;

            for( int k = 0 ; k < len ; k++ ){

                if( *( *( words + i ) + j ) == *( s + k ) ){
                    
                    //if the character is in the chars, setting flag,
                    //adding the number of count, clearing the element
                    flag = 1;
                    index++;
                    *( s + k ) = '.';
                    break;

                }

            }

            //if the character of the word does not in the chars, stop comparing
            if( flag == 0 ){

                break;

            }

        }

        //if all the characters is in the chars, index will equal the length of the
        //word
        if( index == end ){

            sum += index;

        }

    }

    return sum;
    
}
```

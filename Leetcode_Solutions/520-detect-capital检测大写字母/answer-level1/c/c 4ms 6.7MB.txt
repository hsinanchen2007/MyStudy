```
/**
*
*整体思路：
*1.先判断长度，长度为0或者1，返回true
*2.判断第二个元素
*   a.如果为大写，则从元素0开始全部都要大写
*   b.如果为小写，则从元素2开始全部都要小写
*   c.不满足以上两个条件返回false
*3.返回true
*/


bool detectCapitalUse( char * word ){

    //if the length of word is 0 or 1, return true
    if( *( word + 0 ) == '\0' || *( word + 1 ) == '\0' ){

        return true;

    }

    //if the second element is upper, all the elements in the word must be upper
    if( *( word + 1 ) <= 'Z' && *( word + 1 ) >= 'A' ){


        for( int i = 0 ; *( word + i ) != '\0' ; i++ ){

            if( !( *( word + i ) <= 'Z' && *( word + i ) >= 'A' ) ){

                return false;
                
            }

        }

    } else {

        //if the second element is not upper, from the third tp the end elements in the word 
        //must be not upper
        for( int i = 2 ; *( word + i ) != '\0' ; i++ ){

            if( !( *( word + i ) <= 'z' && *( word + i ) >= 'a' ) ){

                return false;
                
            }

        }

    }

    return true;
    
}
```

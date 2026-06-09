```
/**
*
*整体思路：
*1.计算words里面经过f函数的结果，保存在动态内存中
*2.对quires数组进行遍历，计算当前f函数结果，与缓冲区数据进行比较，计算小于对应的个数
*
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * numSmallerByFrequency( char ** queries , int queriesSize , char ** words , int wordsSize , int * returnSize){

    //alloclating memorise to save the result of function in words
    int * buffer = ( int * )malloc( sizeof( int ) * wordsSize );
    //alloclating memorise to save the number of function's result smaller than that in words
    int * result = ( int * )malloc( sizeof( int ) * queriesSize );
    *returnSize = queriesSize;

    for( int i = 0 ; i < wordsSize ; i++ ){

        //spposing the first character is the most small character in the string
        char ch = *( *( words + i ) + 0 );
        //the parameter of count is used to calculating the number of smallest character in the string
        int count = 1;

        for( int j = 1 ; *( *( words + i ) + j ) != '\0' ; j++ ){

            //if current element smaller than ch, updating ch and count
            if( *( *( words + i ) + j ) < ch ){

                ch = *( *( words + i ) + j );
                count = 1;

            } else if( *( *( words + i ) + j ) == ch ){

                count++;

            }

        }

        *( buffer + i ) = count;

    }

    for( int i = 0 ; i < queriesSize ; i++ ){

        //spposing the first character is the most small character in the string
        char ch = *( *( queries + i ) + 0 );
        //the parameter of count is used to calculating the number of smallest character in the string
        //the parameter of num is used to calulating the number of buffer's element that
        //bigger than count
        int count = 1 , num = 0;

        for( int j = 1 ; *( *( queries + i ) + j ) != '\0' ; j++ ){

            //if current element smaller than ch, updating ch and count
            if( *( *( queries + i ) + j ) < ch ){

                ch = *( *( queries + i ) + j );
                count = 1;

            } else if( *( *( queries + i ) + j ) == ch ){

                count++;

            }

        }

        //comparing the word's result to quires string
        for( int j = 0 ; j < wordsSize ; j++ ){

            if( *( buffer + j ) > count ){

                num++;

            }

        }

        *( result + i ) = num;

    }

    free( buffer );

    return result;

}
```

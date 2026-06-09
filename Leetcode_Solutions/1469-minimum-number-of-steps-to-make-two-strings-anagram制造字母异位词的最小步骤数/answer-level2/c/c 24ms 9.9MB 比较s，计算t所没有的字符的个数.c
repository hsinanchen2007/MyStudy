```
/**
*
*整体思路
*1.申请52个char类型长度的动态内存，用于存放每种字母类型的个数，同时初始化计数为0
*2.遍历字符串s，计算字符串s中每种字符类型的个数，存放于缓冲区buffer中
*3.遍历字符串t，计算字符串t中所能抵消的字符类型个数，更新缓冲区buffer
*5.遍历缓冲区，所有大于1的数全部累加到计数器count中
*6.释放缓冲区并返回结果
*/

int minSteps( char * s , char * t ){

    //the parameter of count used to save the number of different characters between s and t
    int count = 0;
    //alloclating memory to save the number of each type characters in s and t
    int * buffer = ( int * )malloc( sizeof( int ) * 26 );

    //intializing the memory
    for( int i = 0 ; i < 26 ; i++ ){

        *( buffer + i ) = 0;

    }

    //visiting the string of s to calculating the number of each type characters
    for( int i = 0 ; *( s + i ) != '\0' ; i++ ){

        *( buffer + *( s + i ) - 97 ) += 1;  

    }

    //visiting the string of t to calculating the number of each type characters
    for( int i = 0 ; *( t + i ) != '\0' ; i++ ){

        *( buffer + *( t + i ) - 97 ) -= 1;  

    }

    //calculating the total number of diierent characters between s and t
    for( int i = 0 ; i < 26 ; i++ ){

        if( *( buffer + i ) > 0 ){

            count += *( buffer + i );

        }

    }

    free( buffer );

    return count;


}
```

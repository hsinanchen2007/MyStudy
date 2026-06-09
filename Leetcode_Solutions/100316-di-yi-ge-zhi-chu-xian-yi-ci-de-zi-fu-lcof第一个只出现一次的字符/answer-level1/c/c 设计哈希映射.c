```
/**
*数据存储说明： ... 9 8 7 6 5 4 3 2 1: 5-高位，存储第一次出现字符的下标，1-4用于存放当前字符个数 
*整体思路：
*1.设计一个长度为128的哈希集合buffer，遍历字符串，计算每个字符出现的次数，存储在buffer中
*2.如果当前字符第一次出现，则在高位存下当前字符的下标len，否则直接个数加1
*3.遍历哈希集合，判断个数为1的字符，*( buffer + j ) / 10000 是否小于min，如果是，证明当前字符比min
*  存储的字符出现的更早
*4.判断 min==len ，如果成立，直接返回' '，如果不是，返回*( s + min )
*/


char firstUniqChar( char * s ){

    //allocalting memory to save the number of character showing in string s 
    int * buffer = ( int * )malloc( sizeof( int ) * 128 );
    //the parameter of min is the minimun of index of character showing in string s 
    //the parameter of len is the length of string s
    int min = 0 , len = 0;

    //visiting string s
    for( ; *( s + len ) != '\0' ; len++ ){

        //if current element shows in string s first time, saving the index of it
        if( *( buffer + *( s + len ) ) < 0 ){

            *( buffer + *( s + len ) ) = len * 10000 + 1; 

        } else {

            *( buffer + *( s + len ) ) += 1;

        }

    }

    //intializing the value of min
    min = len;
    *( s + 0 ) = ' ';

    for( int j = 0 ; j < 128 ; j++ ){

        //if the number of current character if 1, comparing to the value of min
        if( *( buffer + j ) % 10000 == 1 && *( buffer + j ) / 10000 < min ){

            //updating the value of *( s + 0 )
            min = *( buffer + j ) / 10000;
            *( s + 0 ) = j;

        }

    }

    //freeing the memory buffer
    free( buffer );
    return *( s + 0 );

}
```

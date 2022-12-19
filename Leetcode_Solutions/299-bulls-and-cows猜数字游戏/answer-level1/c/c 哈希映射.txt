```

/**
*动态内存数据存储说明：大于10000的用于映射字符串s对应的元素个数，低于10000的映射字符串g对应的元素个数
*整体思路：
*1.申请一个长度为10的动态内存，用于映射字符串secret和字符串guess，初始化同位置同元素极计数器bull=0，
* 初始化同元素不同位置计数器cow=0
*2.遍历字符串，如果两个字符串当前元素相同，则更新计数器bull，
*  如果不同则分别更新*( secret + i )所映射的集合的大于10000的值，以及*( guess + i )映射的低于10000
*  的值
*3.遍历映射集合，cow += 当前高位和地位对应的最小值，
*  即比较*( buffer + i ) / 10000 和 *( buffer + i ) % 10000大小，选取最小值加到cow
4.分别将bull和cow转换成字符串
5.释放缓冲区buffer，返回result
*/

/**
*Function: changing integer to string from right to left, then, reversing the string
*@param: char * s : the memory used to save the finall result
*@param: int val : the integer ready to be changed
*@param: int start : the first index in string s used to save the result
*Return: int : the length of the result
*/
int integerToString( char * s , int val , int start ){

    //the parameter of i is the current pointer of string s
    //the parameter of len is the length of s
    int i = start , len = 0;

    //if the value of val is zero, returning "0"
    if( val == 0 ){

        *( s + start++ ) = '0';
        *( s + start ) = '\0';
        return start;

    }

    //changing the integer to string bit by bit
    while( val > 0 ){

        *( s + i++ ) = val % 10 + 48;
        val /= 10;

    }

    len = i;
    *( s + i-- ) = '\0';

    //reversing the string
    while( start < i ){

        char ch = *( s + start );
        *( s + start++ ) = *( s + i );
        *( s + i-- ) = ch;

    }

    return len;

}

char * getHint( char * secret , char * guess ){

    //alloclating memory buffer used as a hashMap
    int * buffer = ( int * )malloc( sizeof( int ) * 10 );
    //alloclating memory to save the final result of process
    char * result = ( char * )malloc( sizeof( char ) * 20 );
    int bull = 0 , cow = 0;

    //intializing the meomry of buffer
    for( int i = 0 ; i < 10 ; i++ ){

        *( buffer + i ) = 0;

    }

    //visiting string secret and string guess
    for( int i = 0 ; *( secret + i ) != '\0' ; i++ ){

        //if the value of current element in secret equals to one in gurss, updating the bull
        if( *( secret + i ) == *( guess + i ) ){

            bull++;

        } else {
            
            //otherwise, updating the hashMap
            *( buffer + *( secret + i ) - 48 ) += 10000;
            *( buffer + *( guess + i ) - 48 ) += 1;

        }

    }

    //visiting the hashMap, calculating the value of cow
    for( int i = 0 ; i < 10 ; i++ ){

        int t1 = *( buffer + i ) / 10000 , t2 = *( buffer + i ) % 10000;

        cow += ( t1 > t2 ? t2 : t1 );

    }

    //changing the value of bull to string
    int len = integerToString( result , bull , 0 );

    //appending the character of 'A'
    *( result + len++ ) = 'A';
    //changing the value of bull to string
    len = integerToString( result , cow , len );
    //appending the character of 'A'
    *( result + len++ ) = 'B';
    //appending the ending flag of string to result
    *( result + len ) = '\0';
    //freeing buffer
    free( buffer );

    return result;

}
```

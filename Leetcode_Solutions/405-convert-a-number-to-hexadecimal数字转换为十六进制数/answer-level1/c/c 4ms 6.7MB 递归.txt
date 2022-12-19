```
/**
*
*整体思路：
*1.申请动态内存buffer用于存放结果，并将符号数num强转为unsigned int
*2.如果num = 0,直接更新缓冲区buffer后，返回buffer
*3.调用递归函数，返回值为int ，用于返回最后的下标
*4.递归函数不断递归当前值/16，并传入缓冲区，同时返回最后的下标
*/

/**
*Function: changing the value of decimalism to hex
*@param: unsigned int num : the number ready to be changed
*@param: char * buffer : the memory used to save the result of the process
*return: int : the last index of buffer
*/
int uintToHex( unsigned int num , char * buffer ){

    //the parameter of index used to save the last index of buffer
    int index = 0;

    //if the value of num is bigger than zero, continuing next fun
    if( num > 0 ){

        index = uintToHex( num / 16 , buffer );

    //if the value of current num is zero, return the last index of buffer is zero
    } else {

        return 0;

    }

    //appending the character of current hex of num to the end of buffer
    *( buffer + index++ ) = ( "0123456789abcdef" )[ num % 16 ];

    return index;

}

char * toHex( int num ){

    //alloclating memory to save the result
    char * buffer = ( char * )malloc( sizeof( char ) * 9 );
    //forcing change the type of num
    unsigned int t = num;

    //if the value of current num is zero, returning "0"
    if( num == 0 ){

        *( buffer + 0 ) = '0';
        *( buffer + 1 ) = '\0';
        return buffer;

    }

    //using the function to change num
    num = uintToHex( t , buffer );
    *( buffer + num ) = '\0';

    return buffer;

}
```

```
/**
*
*整体思路：
*1.申请动态内存buffer，维护一个指针指向该内存，同时初始化一个计数器count，维护一个指针指向S
*2.遍历字符串S，如果不为'\0'，否则进入5步骤，
*3.如果i与i+1的元素相同，count计数加一，继续下一趟遍历，进入步骤2，如果不同，进入步骤4
*4.存入当前的元素，调用函数counterToString，将计数器的值存入缓冲区，初始化计数器count，进入步骤2
*5.存入最后一个元素，加上字符串结束标志，判断S与buffer长度大小，决定返回的字符串
*/

/**
*Function: integer to string
*@param: char * buffer : the memory used to save the result
*@param: int index : the current pointer in buffer
*@param: int value : the integer ready to changed
*return: int : the pointer after updating
*/
int counterToString( char * buffer , int index , int value ){

    //the parameter of i is the former pointer of buffer
    //the parameter of j is the current pointer of buffer
    int  j = index , i = index; 

    //saving the value of value to buffer, updating the value of j
    while( value != 0 ){

        *( buffer + j++ ) = value % 10 + 48;
        value /= 10;

    }

    //remembering the final pointer
    index = j;

    j--;

    //resvering the string
    while( i < j ){

        char ch = *( buffer + i );
        *( buffer + i++ ) = *( buffer + j );
        *( buffer + j-- ) = ch;

    }

    //returning the final pointer
    return index;

}

char * compressString( char * S ){

    //the parameter of len used to save the length of S
    int len = strlen( S );

    //alloclating memory to save the result
    char * buffer = ( char * )malloc( sizeof( char ) * 1024 * 1024 );
    //the parameter of index is the pointer of buffer
    //the parameter of count used to save the number of each character of string S
    //the parameter of i is the pointer of S
    int index = 0 , count = 1 , i = 0;

    for(  ; i < len && i + 1 < len ; i++ ){

        //if current element equals to next element
        if( *( S + i ) == *( S + i + 1 ) ){

            count++;
            continue;

        }

        //saving current element and the number of it to buffer
        *( buffer + index++ ) = *( S + i );
        index = counterToString( buffer , index , count );
        count = 1;

    }

    //saving the last element and it's number to buffer
    if( len != 0 ){

        *( buffer + index++ ) = *( S + i );
        index = counterToString( buffer , index , count );

    }
    
    //appending the ending flag of string to buffer
    *( buffer + index ) = '\0';

    //comparing the length of string S to buffer
    if( index >= len ){

        return S;

    }

    return buffer;

}
```

```
/**
*
*整体思路：
*1.申请动态内存，并初始化相应的指针，清零进位标志位add_flag
*2.从字符串num1和字符串num2末尾向前遍历，同时对当前位做加法，
*  加法运算结果分别存入进位标志位，当前缓冲区buffer中
*3.遍历完字符串后，判断进位标志位是否进位，如果是，则添加进buffer中
*4.添加字符串结束标志位后，对缓冲区buffer进行逆序
*
*/

char * addStrings( char * num1 , char * num2 ){

    //the parameter of add_bit is carry-bit
    int add_bit = 0;
    //the parameter of i and j is the pointer of num1 and num2 respectively
    int i = strlen( num1 ), j = strlen( num2 );
    //the parameter of len is the length of buffer
    int len = i > j ? i + 2 : j + 2;
    char * buffer = ( char * )malloc( sizeof( char ) * len );

    //updating the pointer of buffer, num1 and num2 
    len = 0;
    i--;
    j--;

    while( i >= 0 || j >= 0 ){

        //the parameter of tmp used to save current calculting result
        int tmp = add_bit;

        if( i >= 0 ){

            tmp += *( num1 + i-- ) - 48;

        }

        if( j >= 0 ){

            tmp += *( num2 + j-- ) - 48;

        }

        //updating the value of add_bit and saving current result in buffer
        add_bit = tmp / 10;
        *( buffer + len++ ) = tmp % 10 + 48;

    }

    //if the value of add_bit is not zero, appending to the end of buffer
    if( add_bit > 0 ){

        *( buffer + len++ ) = add_bit + 48;

    }

    //appending the ending flag of string to buffer
    *( buffer + len ) = '\0';
    i = 0;
    j= len - 1;

    //reversing buffer
    while( i < j ){

        char ch = *( buffer + i );
        *( buffer + i++ ) = *( buffer + j );
        *( buffer + j-- ) = ch;

    }

    return buffer;

}
```

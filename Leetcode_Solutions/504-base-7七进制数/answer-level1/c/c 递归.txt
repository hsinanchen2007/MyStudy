![QGQUE2DXN0U~9PMC09AW98Q.png](https://pic.leetcode-cn.com/9f4fddcd9635466937eeafbf7e64289dafad4adb60c500aa7a488d477575913f-QGQUE2DXN0U~9PMC09AW98Q.png)



```
/**
*
*整体思路：
*1.首先判断是否为0，如果是，则返回"0"
*2.判断是否小于0，如果是，在字符串前面加字符'-'，，并绝对化num
*3.调用递归函数，将十进制转化成七进制
*4.进入递归函数后，判断value是否为0，如果是，直接返回void，否则进入5步骤
*5.调用递归函数，传入value/7，以及字符串buffer，同时传入指针index，用于存储buffer当前下标
*6.将当前的value%7存入字符串中，更新buffer当前下标
*7.对字符串添加技术标志'\0'
*/

/**
*Function: changing the integer to Seven hexadecimal
*@param: int value : the value ready to be changed
*@param: char * buffer : the memory used to save the result
*@param: int * index : the current index of buffer 
*return: void
*/
void deciToSevenHex( int value , char * buffer , int * index ){

    //if current value is zero, return void
    if( value == 0 ){

        return ;

    }

    //continuing using the fun to calculating next priority
    deciToSevenHex( value / 7 , buffer , index );
    //save cuurent priority of value
    *( buffer + *index ) = value % 7 + 48;
    *index += 1;

}

char * convertToBase7( int num ){

    //allocalting memory to save the result
    char * buffer = ( char * )malloc( sizeof( char ) * 13 );
    //the parameter of len is the length of buffer
    int len = 0;

    //if the value of num is zero, returning "0"
    if( num == 0 ){

        *( buffer + len++ ) = '0';
        *( buffer + len ) = '\0';
        return buffer;

    //if the value of num smaller than zero, turning over it and appending the character of'-'
    //to buffer
    } else if( num < 0 ){

        *( buffer + len++ ) = '-';
        num *= -1;

    }

    deciToSevenHex( num , buffer , &len );
    //appending the ending flag of string to buffer
    *( buffer + len ) = '\0';

    return buffer;

}
```

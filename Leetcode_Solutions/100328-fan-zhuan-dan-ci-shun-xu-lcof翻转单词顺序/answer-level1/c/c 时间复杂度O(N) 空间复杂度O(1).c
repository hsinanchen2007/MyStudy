```
/**
*
*整体思路：
*1.首先去除字符串前面多余的空格' '，同时判断是否越界
*1.再删除字符串s中间以及尾部的多余' '，同时追加新的字符串结束标志'\0'
*2.利用reverseString函数翻转字符串s
*4.初始化单词起始点为i = 0, i 用于记录每个单词首字母的下标
*5.利用指针j遍历字符串s，如果当前元素不为' '，则继续，如果当前元素为' '，直接传入i 和j-1，翻转该单词
*6.返回字符串
*/

/**
*Function: reversing substring from the index of start to end
*@param: char * : the substring ready to be reversed
*@param: int start : the index of start in substring
*@param: int end: the index of end in substring
*return: void
*/
void reverseString( char * s , int start , int end ){

    while( start < end ){

        char ch = *( s + start );
        *( s + start++ ) = *( s + end );
        *( s + end-- ) = ch;

    }

}

char * reverseWords( char * s ){

    //the parameter of len is the length os tring s
    //the parameter of i is the pointer of string s
    int len = 0 , i = 0;

    //deleting the space in the front of string s
    if( *( s + i ) == ' ' ){

        while( *( s + i ) != '\0' && *( s + i ) == ' ' ){

            i++;

        }

    }
    
    //making sure the index is legal
    if( *( s + i ) == '\0' ){

        return "\0";

    }

    //saving the first character to s
    *( s + len++ ) = *( s + i++ );

    //deleting the spaces in string s
    for( ; *( s + i ) != '\0' ; i++ ){

        if( *( s + i - 1 ) == ' ' && *( s + i ) != ' ' ){

            *( s + len++ ) = ' ';

        }

        if( *( s + i ) != ' ' ){

            *( s + len++ ) = *( s + i );

        }

    }

    //appending the ending flag of string
    *( s + len ) = '\0';
    //reversing the string
    reverseString( s , 0 , len - 1 );

    i = 0;

    //reversing the words in the string
    for( int j = 0 ; j < len ; j++ ){

        if( *( s + j ) != ' ' ){

            continue;

        }

        //reversing current word
        reverseString( s , i , j - 1 );
        i = j + 1;

    }

    //reversing the last word
    reverseString( s , i , len - 1 );

    return s;

}
```

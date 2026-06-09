```
/**
*
*整体思路：
*1.遍历字符串，遇到' '时，将改段的子字符串传入翻转函数内
*2.如果读到字符串结束标志，则在循环外进行一次翻转
*
* 翻转使用两遍向中间逼近方法
*
*/

//reversing the srting from both side
void reverseString( char * s , int left , int right ){

    while( left < right ){

        //increasing the left pointer
        char ch = *( s + left );
        *( s + left++ ) = *( s + right );
        //decreasing the right pointer
        *( s + right-- ) = ch;;

    }

}

char * reverseWords( char * s ){

    //the param is used to mark the starting of the subString
    int left = -1 , i = 0 ;

    for( i = 0 ; *( s + i ) != '\0' ; i++ ){

        //when encountering the character of space, excuting the function
        if( *( s + i ) == ' ' ){

            reverseString( s , left + 1 , i - 1 );
            left = i;

        }

    }

    //making sure that you have reversed the last word
    reverseString( s , left + 1 , i - 1 );

    return s;

}
```

```
代码块/**
*
*整体思路：
*1.分别遍历字符串S和T，对退格进行操作，分别维护新的长度指针len_s和len_b
*2.如果len_s!=len_b，直接返回false
*3.同时遍历字符串S和T，判断元素是否相等，如果存在某个对应下标元素不等，直接返回false
*4.直接返回true
*/

bool backspaceCompare( char * S , char * T ){

    //the parameter of len_s is the length of string S after updating 
    //the parameter of len_t is the length of string T after updating
    int len_s = 0 , len_t = 0;

    //updating string S according character of '#', and updating the value of len_s
    for( int i = 0 ; *( S + i ) != '\0' ; i++ ){

        //if current element is '#', deleting former element
        //you should make sure len_s does not smaller than 0
        if( *( S + i ) == '#' && len_s > 0 ){

            len_s--;

        //if current element is not '#', saving it to string S
        } else if( *( S + i ) != '#' ){

            *( S + len_s++ ) = *( S + i );

        }
        
    }

    //updating string T according character of '#', and updating the value of len_t
    for( int i = 0 ; *( T + i ) != '\0' ; i++ ){

        //if current element is '#', deleting former element
        //you should make sure len_s does not smaller than 0
        if( *( T + i ) == '#' && len_t > 0 ){

            len_t--;

        //if current element is not '#', saving it to string T
        } else if( *( T + i ) != '#' ){

            *( T + len_t++ ) = *( T + i );

        }
        
    }

    //if the length of T is not equal to the length of S, returning false
    if( len_t != len_s ){

        return false;

    }

    //comparing the elements between string S and string T
    for( int i = 0 ; i < len_s ; i++ ){

        //if current element in string S and T are different, retuning false
        if( *( S + i ) != *( T + i ) ){

            return false;

        }

    }

    return true;

}
```

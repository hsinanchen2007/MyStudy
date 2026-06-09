```
/**
*
*整体思路：
*1.首先对偶下标字符进行冒泡排序，再对奇下标字符进行冒泡排序，注意下标边界条件
*2.令计数为二维数组长度，遍历二维数组，如果发现此时字符串等价，则计数减一，同时
*  清除该数组
*
*/

/**
*Function: using bubble sort changing elements according to 
*the index of even and odd number 
*@param: char * s : the string ready to be changed
*return: void :
*/
void sort( char * s  ){

    int len = strlen( s );

    //changing the element that has index of even number
    for( int i = 0 ; i < len ; i += 2 ){

        for( int j = 0 ; j < len - i - 2 ; j += 2 ){

            if( *( s + j ) > *( s + j + 2 ) ){

                char ch = *( s + j );
                *( s + j ) = *( s + j + 2 );
                *( s + j + 2 ) = ch;

            }

        }

    }

    //changing the element that has index of odd number
    for( int i = 1 ; i < len ; i += 2 ){

        for( int j = 1 ; j < len - i - 1 ; j += 2 ){

            if( *( s + j ) > *( s + j + 2 ) ){

                char ch = *( s + j );
                *( s + j ) = *( s + j + 2 );
                *( s + j + 2 ) = ch;

            }

        }

    }

}

int numSpecialEquivGroups( char ** A , int ASize ){

    int count = ASize;

    for( int i = 0 ; i < ASize ; i++ ){

        sort( *( A + i ) );

    }

    for( int i = 0 ; i < ASize ; i++ ){

        for( int j = i + 1 ; j < ASize ; j++ ){

            //if there is a string equal current string, substract the count, 
            //and clear the string
            if( strcmp( *( A + i ) , *( A + j ) ) == 0 ){

                count--;
                *( *( A + i ) + 0 ) = '\0';

            }

        }

    }

    return count;

}
```

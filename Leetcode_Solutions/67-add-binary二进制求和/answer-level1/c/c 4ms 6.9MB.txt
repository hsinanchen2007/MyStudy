```
/**
*
*整体思路：
*1.计算字符串a,b的长度
*2.申请动态内存，注意此时应该预留两个char的空间，预留给进位标志位和'\0'
*3.逆序相加进位标致、a和b字符串的元素值，更新进位标志位
*/

char * addBinary( char * a , char * b ){

    //the parameter of len is used to save the length of buffer
    //the parameter of flag_bit is current sum of elements in a and b is bigger than 2 or not
    //the parameter of len_a is the length of string a
    //the parameter of len_b is the length of string b
    int len = 0 , flag_bit = 0 , len_a = 0 , len_b = 0;

    //calculating the length of string a and b
    while( *( a + len_a++ ) != '\0' );
    while( *( b + len_b++ ) != '\0' );

    //making sure the size of the memory can save the result
    len = len_b > len_a ? len_b : len_a ;

    //alloclating memory to save the result
    char * buffer = ( char * )malloc( sizeof( char ) * ( len + 1 ) );
    
    len_a--;
    len_b--;
    len = 0;


    //visiting string a and b
    for( int i = 1 ; i <= len_a || i <= len_b ; i++ ){

        //the parameter of sum is current result of adding element in a to 
        //element in b
        int sum = flag_bit;

        //if the index of string a is legal
        if( i <= len_a ){

            sum = sum + *( a + len_a - i ) - 48;

        }

        //if the index of string a is legal
        if( i <= len_b ){

            sum = sum + *( b + len_b - i ) - 48;

        }

        //updating the flag
        flag_bit = sum / 2;
        //saving current result to buffer
        *( buffer + len++ ) = sum % 2 + 48;

    }

    if( flag_bit == 1 ){

        *( buffer + len++ ) = '1';

    }

    //appending the ending flag of string to the end of buffer
    *( buffer + len ) = '\0';

    //reversing the string in buffer
    for( int i = 0 , j = len - 1 ; i < j ; ){

        char ch = *( buffer + i );
        *( buffer + i++ ) = *( buffer + j );
        *( buffer + j-- ) = ch;

    }
    
    return buffer;
    
}
```

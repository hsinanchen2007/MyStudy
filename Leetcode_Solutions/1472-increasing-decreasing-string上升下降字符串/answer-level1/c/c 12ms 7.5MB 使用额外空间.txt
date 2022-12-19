```
/**
*num数组元素存储说明：32 31 30... 5 4 3 2 1 , 1-2位：存放26个字母， 3-31位存放每个字母在字符串s中的个数
*整体思路：
*1.首先计算字符串s长度len，如果len小于0，直接返回字符串s
*2.申请长度为26的动态缓冲区num，用来记录字符串s出现的字母以及对应的次数，说明如上
*3.快排字符串s(该步骤可以使num存放的数据有序)
*4.统计字符串s中出现的字母以及对应的次数，同时记录字母的个数
*5.维护一个指向s的指针count，保证指针count小于s的有效长度len，如果count > len，则执行步骤9
*6.正序遍历num，如果当前字母个数大于0，就添加到字符串s中，更新指针count
*7.逆序遍历num，如果当前字母个数大于0，就添加到字符串s中，更新指针count
*8.重复5-7
*9.释放动态内存num，返回字符串s
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( char * )a - *( char * )b;

}

char * sortString( char * s ){

    //the parameter of len is length of s
    int len = strlen( s );

    //if s is NULL, returning s
    if( len == 0 ){

        return s;

    }

    //the parameter of len_n is the length of num 
    int len_n = 0 , count = 1;
    //alloclating memory to save alpha and the number of it in string s
    int * num = ( int * )malloc( sizeof( int ) * 26 );

    //quick sort
    qsort( s , len , sizeof( char ) , cmp );

    //saving each character and the number of it in string s
    for( int i = 0 ; i < len - 1 ; i++ ){

        //if current alpha equal to next alpha, updating the number of count
        if( *( s + i ) == *( s + i + 1 ) ){

            count++;
            continue;

        }

        //saving current alpha to num including it's number
        *( num + len_n++ ) = count * 100 + *( s + i ) - 97;
        //clearing the value of count
        count = 1;

    }

    //saving the last alpha in string s to num
    *( num + len_n++ ) = count * 100 + *( s + len - 1 ) - 97;

    //the parameter of count is the pointer of s at this monment
    for( count = 0 ; count < len ; ){

        int j = 0;

        //visiting num from left to right
        for( ; j < len_n ; j++ ){

            //if the number of current element is not zero,
            //appending the alapha of current element to s 
            if( *( num + j ) / 100 != 0 ){

                *( s + count++ ) = *( num + j ) % 100 + 97;
                *( num + j ) -= 100;

            }

        }

        j--;

        //visiting num from right to left
        for( ; j >= 0 ; j-- ){

            //if the number of current element is not zero,
            //appending the alapha of current element to s 
            if( *( num + j ) / 100 != 0 ){

                *( s + count++ ) = *( num + j ) % 100 + 97;
                *( num + j ) -= 100;

            }

        }

    }

    //freeing the memory of num
    free( num );

    return s;

}





```

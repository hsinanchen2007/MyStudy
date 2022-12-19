```
/**
*
*整体思路：只要magzine的不同类型字符的总数大于ransomNote的即可
*1.申请动态内存，用于计算a-z和A-Z对应的个数
*2.遍历字符串ransomNote，对应缓冲区字符个数加一
*3.遍历字符串magazine，对应缓冲区字符个数减一
*4.遍历缓冲区，如果当前元素大于0，直接返回false
*5.返回true
*/

bool canConstruct( char * ransomNote , char * magazine ){

    //alloclating memory to save the number of each alpha in string
    int * buffer = ( int * )malloc( sizeof( int ) * 52 );

    //intializing the value of element in buffer
    for( int i = 0 ; i < 26 ; i++ ){

        *( buffer + i ) = 0;
        *( buffer + i + 26 ) = 0;

    }

    //visiting string ransomNote, and updating the value of element in 
    //buffer according current character in ransomNote
    for( int i = 0 ; *( ransomNote + i ) != '\0' ; i++ ){

        if( *( ransomNote + i ) >= 'a' && *( ransomNote + i ) <= 'z' ){

            *( buffer + ( *( ransomNote + i ) - 97 ) ) += 1;
            continue;

        }

        *( buffer + ( *( ransomNote + i ) - 65 + 26 ) ) += 1;

    }

    //visiting string magazine, and updating the value of element in 
    //buffer according current character in magazine
    for( int i = 0 ; *( magazine + i ) != '\0' ; i++ ){

        if( *( magazine + i ) >= 'a' && *( magazine + i ) <= 'z' ){

            *( buffer + ( *( magazine + i ) - 97 ) ) -= 1;
            continue;

        }

        *( buffer + ( *( magazine + i ) - 65 + 26 ) ) -= 1;

    }
    
    //visiting buffer, 
    for( int i = 0 ; i < 26 ; i++ ){
        
        //if the value of elements in buffer is bigger than zero, return false
        if( *( buffer + i ) > 0 || *( buffer + i + 26 ) > 0 ){

            free( buffer );
            return false;

        }

    }

    free( buffer );
    return true;

}
```

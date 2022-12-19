```
/**
*
*整体思路：
*1.分别计算字符串长度，
*2.快速排序
*3.利用比较函数比较
*
*/

int cmp( const void * a , const void * b ){

    return *( char * )a - *( char * )b;

}

bool isAnagram(char * s, char * t){

    int len_s = 0 , len_t = 0;

    while( *( s + len_s++ ) != '\0' );
    while( *( t + len_t++ ) != '\0' );

    len_s--;
    len_t--;

    if( len_s != len_t ){

        return false;

    }

    qsort( s , len_s , sizeof( char ) , cmp );
    qsort( t , len_t , sizeof( char ) , cmp );

    if( strcmp( s , t ) == 0 ){

        return true;

    }

    return false;

}
```

```
/*int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}
*/

/**
*
*整体思路：
*1.比较前后元素，如果相等则计数加一，进入下一次循环，
*   否则，判断是否大于四分之一的arrSize，是则返回当前元素，否则清零计数
*
*/

int findSpecialInteger( int * arr , int arrSize ){

    //qsort( arr , arrSize , sizeof( int ) , cmp );
    int count = 0;

    for( int i = 0 ; i < arrSize - 1 ; i++ ){

        if( *( arr + i ) == *( arr + i + 1 ) ){

            count++;
            continue;

        }

        if( count >= ( arrSize / 4 ) ){

            return *( arr + i );

        }

        count = 0;

    }

    return *( arr + arrSize - 1 );

}
```

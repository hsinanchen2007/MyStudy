```
/**
*
*整体思路：插入排序
*1.将各自参数减一
*2.比较末尾A,B数组两个元素当前大小，大的元素插入，
*
*/

void merge(int * A , int ASize , int m , int * B , int BSize , int n ){

    m--;
    n--;
    ASize--;

    while( n >= 0 && m >= 0 ){

        if( *( A + m ) > *( B + n ) ){

            *( A + ASize-- ) = *( A + m-- );
            continue;

        }

        *( A + ASize-- ) = *( B + n-- );


    }

    while( m >= 0 ){

        *( A + ASize-- ) = *( A + m-- );

    }

    while( n >= 0 ){

        *( A + ASize-- ) = *( B + n-- );

    }

}
```

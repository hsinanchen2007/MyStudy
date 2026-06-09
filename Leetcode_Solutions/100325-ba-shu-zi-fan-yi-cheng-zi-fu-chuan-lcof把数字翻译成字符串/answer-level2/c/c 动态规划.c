```
/**
*
*整体思路：动态规划
*
*
*/

int translateNum( int num ){

    if( num < 10 ){

        return 1;

    }

    int * buffer = ( int * )malloc( sizeof( int ) * 10 );
    int count = 0 , len = 0 , form = 1 , curr = 1;

    while( num > 0 ){

        *( buffer + len++ ) = num % 10;
        num /= 10;

    }

    for( int i = 0 , j = len - 1 ; i < j ; ){

        int tmp = *( buffer + i );
        *( buffer + i++ ) = *( buffer + j );
        *( buffer + j-- ) = tmp;

    }

    for( int i = 1 ; i < len ; i++ ){

        if( *( buffer + i - 1 ) != 0 && *( buffer + i - 1 ) * 10 + *( buffer + i ) <= 25 ){

            count = form + curr;

        } else {

            count = curr;

        }

        form = curr;
        curr = count;

    }

    return count;

}
```

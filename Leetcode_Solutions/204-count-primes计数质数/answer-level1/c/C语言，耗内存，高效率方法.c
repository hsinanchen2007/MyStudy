
执行用时 :28 ms, 在所有 c 提交中击败了85.58%的用户
内存消耗 :9.9 MB, 在所有 c 提交中击败了41.38%的用户


int countPrimes(int n){

    int count = 0 ;

    if( n > 2 ){

        count++;

        //为了解决内存消耗问题，在这里定义为char类型，从18.7M左右降到9.9M左右
        char * buf = ( char * )malloc( sizeof( char ) * n );

        for( int i = 3 ; i < n ; i += 2 ){

            buf[ i ] = 1;

        }

        for( int i = 3 ; i < n ; i += 2 ){

            if( buf[ i ] == 1 ){

                count++;

                for( int j = 2 ; j * i < n ; j++ ){

                    buf[ i * j ] = 0;

                }

            }

        }

    }

    return count;

}
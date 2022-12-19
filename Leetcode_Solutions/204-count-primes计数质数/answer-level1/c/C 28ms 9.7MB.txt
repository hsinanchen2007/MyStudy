/**
* 主要思路：
* 采用帅选法的同时，牺牲一点内存，达到提速效果，
* 
*/

/**
* count the primes from 3 to n
* @param: int n, the end of the integerity
* @param: int, the number of the primes from 3 to n
*/
int countPrimes(int n){

    int count = 0 ;

    //if n smaller than 2, return 0
    if( n > 2 ){

        //2 is a prime number
        count++;

        char * buf = ( char * )malloc( sizeof( char ) * n );

        //make sure the index of the odd set 1, 
        for( int i = 3 ; i < n ; i += 2 ){

            buf[ i ] = 1;

        }

        //check the buffer and count the number
        for( int i = 3 ; i < n ; i += 2 ){

            //if the element is not prime, skip it
            if( buf[ i ] == 1 ){

                count++;

                //if the number is prime, check again
                for( int j = 2 ; j * i < n ; j++ ){

                    buf[ i * j ] = 0;

                }

            }

        }

    }

    return count;

}
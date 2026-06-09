```
/**
*
*整体思路
*1.遍历L-R区间的数
*2.计算二进制中1的个数
*3.判断1的个数是否为素数
*
*/

/**
*Function: return the number of binaries of the number
*@param: int num : the number ready to be calculated
*return: int : the number of 1 in the binary
*
*/
int Binary( int num ){

    int one = 0;

    while( num > 0 ){

        if( num % 2 == 1 ){

            one++;

        }

        num /= 2;

    }

    return one;

}

/**
*Function: return the result of the number that is a primer number
*@param: int num : the number ready to be checked
*return: int : 1 : is a primer number, 0 : is not a primer number
*
*/
int isPrime( int num ){

    if( num == 2 ){

        return 1;

    }

    if( num == 1 || num % 2 == 0 ){

        return 0;

    }

    for( int i = 3 ; i * i <= num ; i += 2 ){

        if( num % i == 0 ){

            return 0;
            
        }

    }

    return 1;

}

int countPrimeSetBits( int L , int R ){

    //used to svae the number of the 1 in the binary
    int count = 0;

    for( int i = L ; i <= R ; i++ ){

        if( isPrime( Binary( i ) ) ){

            count++;

        }

    }

    return count;

}
```

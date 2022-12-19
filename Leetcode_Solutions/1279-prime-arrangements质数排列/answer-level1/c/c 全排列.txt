```

/**
*
*整体思路：
*1.计算对应范围内的质数个数num
*2.定义long型数据result，并初始化result=1
*2.分别计算阶乘num!和( n - num )！,同时每计算一次，都对100000007取余
*3.返回时强转long为int，即( int )result
*/

/**
*Function: calculating the number of prime number between 1 to n
*@param: int n : the maximun of border 
*Return: the number of prime number from 1 to n
*/
int primeNumber( int n ){

    //if the value of n smaller than 2, returning 0
    if( n < 2 ){

        return 0;

    }

    //2 is a prime number
    int num = 1;

    //the starting is 3
    for( int i = 3 ; i <= n ; i += 2 ){

        int flag = 1;

        for( int j = 3 ; j * j <= i ; j += 2 ){

            //if the value of current i is not prime number, clearing flag and breaking loop 
            if( i % j == 0 ){

                flag = 0;
                break;

            }

        }

        num += flag;

    }

    return num;

}

int numPrimeArrangements( int n ){

    //calculating tne number of prime number from 1 to n
    int num = primeNumber( n );
    //the parameter of result used to save the final result
    long result = 1;

    //calculating the factorial of num
    for( int i = 2 ; i <= num ; i++ ){

        result = ( result * i ) % 1000000007; 

    }

    //calculating the factorial of ( n - num )
    for( int i = 2 ; i <= n - num ; i++ ){

        result = ( result * i ) % 1000000007; 

    }

    

    return ( int )result;

}
```

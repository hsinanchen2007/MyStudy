```
int fun( int num ){

    int tmp = num;

    if( tmp >= 10 ){

        tmp = 0;

        while( num > 0 ){

            tmp += ( num % 10 );
            num /= 10;

        }

        if( tmp >= 10 ){

            return fun( tmp );

        }

    }

    return tmp;

}

int addDigits( int num ){

    return fun( num );

}
```

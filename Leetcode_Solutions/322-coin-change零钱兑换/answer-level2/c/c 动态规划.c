```

#define min( a , b ) ( a > b ? b : a )

int coinChange(int* coins, int coinsSize, int amount){

    if( coinsSize == 0 && amount > 0 ){

        return -1;

    } else if( amount == 0 ){

        return 0;

    }

    int * buffer = ( int * )malloc( sizeof( int ) * ( amount + 1 ) );

    for( int i = 1 ; i < amount + 1 ; i++ ){

        *( buffer + i ) = amount + 1;

    }

    *( buffer + 0 ) = 0;

    for( int i = 1 ; i < amount + 1 ; i++ ){

        for( int j = 0 ; j < coinsSize ; j++ ){

            if( *( coins + j ) > i ){

                continue;

            }

            *( buffer + i ) = min( *( buffer + i ) , *( buffer + i - *( coins + j ) ) + 1 );

        }

    }

    return *( buffer + amount ) > amount ? -1 : *( buffer + amount);

}
```

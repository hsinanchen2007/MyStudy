```
void rotate( int ** matrix , int matrixSize , int * matrixColSize ){

    for( int i = 0 ; i < matrixSize - i ; i++ ){

        for( int j = 0 ; j < *( matrixColSize + i ) ; j++ ){

            int tmp = *( *( matrix + i ) + j );
            *( *( matrix + i ) + j ) = *( *( matrix + matrixSize - i - 1 ) + j );
            *( *( matrix + matrixSize - i - 1 ) + j ) = tmp;

        }

    }

    for( int i = 0 ; i < matrixSize ; i++ ){

        for( int j = i + 1 ; j < *( matrixColSize + i ) ; j++ ){

            int tmp = *( *( matrix + i ) + j );
            *( *( matrix + i ) + j ) = *( *( matrix + j ) + i );
            *( *( matrix + j ) + i ) = tmp;

        }

    }

}
```

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int * fairCandySwap( int * A , int ASize , int * B , int BSize , int * returnSize){

    *returnSize = 2;

    int sum_A = 0 , sum_B = 0;

    for( int i = 0 ; i < ASize ; i++ ){

        sum_A += *( A + i );

    }

    for( int i = 0 ; i < BSize ; i++ ){

        sum_B += *( B + i );

    }

    for( int i = 0 ; i < ASize ; i++ ){

        for( int j = 0 ; j < BSize ; j++ ){

            if( sum_A - *( A + i ) + *( B + j ) == sum_B + *( A + i ) - *( B + j ) ){
                
                //if the length of A is bigger than the length of B
                if( ASize > BSize ){

                    *( A + 0 ) = *( A + i );
                    *( A + 1 ) = *( B + j );
                    return A;

                }

                //if you exchange the next two line, it will occur a mistake because the first 
                //element is array is the pointer of the array, so it will change
                *( B + 1 ) = *( B + j );
                *( B + 0 ) = *( A + i );
                return B;  

            }

        }

    }

    return A;

}
```

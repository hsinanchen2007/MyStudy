```
/**
*
*整体思路：
*1.利用递归函数，将十进制转成二进制后，取反后存入缓冲区
*2.计算反码的
*
*/

/**
*Function: calculating the priority of 2
*@param int num : the number ready to be calculated
*@param int * buffer : the memorise used to save the priorities
*return : int : the new position of the pointer
*/
int getBit( int num , int * buffer ){

    //the parameter is used to mark the position of the pointer 
    int index = 0;

    if( num > 0 ){

        index = getBit( num / 2 , buffer );
        //save the value into the memorise
        *( buffer + index++ ) = ( num % 2 + 1 ) % 2;

    }

    return index;

}


int findComplement(int num){

    //the memorise used to save the value
    int * buffer = ( int * )malloc( sizeof( int ) * 32 );
    //the final value of the reversing code, and the length of the buffer
    int value = 0 , len = 0;

    len = getBit( num , buffer );
    
    for( int i = 0 ; i < len ; i++ ){

        //calculating the final value
        value = value * 2 + *( buffer + i );

    }

    return value;

}
```

```
/**
*
*整体思路：
*1.对nums进行更新，将所得分数存储在十进制第五位左边，低四位用于存储原始数组中的分数下标
*   即构成了: 最高位-5 : 为分数， 4-0位：为原始数组的下标
*2.对更新后的数组进行快速排序
*3.逆序处理前三名，
*4.逆序计算每个下标对应的名次
*5.返回字符串
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}


/**
*Fcuntion: changing the integer to string and saving in the buffer
*@param: char * buffer : the memory is used to save the result
*@param: the integer is ready to be changed
*return: void
*/
void integerToString( char * buffer , int value ){

    //the parameter of len is the length of buffer
    int len = 0;

    //saving the value of integer to buffer bit by bit
    while( value > 0 ){

        //changing the integer to character
        *( buffer + len++ ) = value % 10 + 48;
        value /= 10;

    }

    //appending the ending flag of string to buffer
    *( buffer + len ) = '\0';

    //keeping the parameter of i to the left of buffer
    //keeping the parameter of j to the right of buffer
    int left = 0 , right = len - 1;

    //reversing the buffer
    while( left < right ){

        char ch = *( buffer + left );
        *( buffer + left++ ) = *( buffer + right );
        *( buffer + right-- ) = ch;

    }

}


char ** findRelativeRanks( int * nums , int numsSize , int * returnSize){

    //intializing the length of the buffer
    *returnSize = numsSize;

    //if nums is NULL, return NULL
    if( numsSize == 0 ){
        
        return NULL;

    }

    //updating all the value of elements in nums 
    for( int i = 0 ; i < numsSize ; i++ ){

        *( nums + i ) = *( nums + i ) * 10000 + i;

    }

    //alloclating memory to save the result of process
    char ** buffer = ( char ** )malloc( sizeof( char * ) * numsSize );
    
    //quick sort
    qsort( nums , numsSize , sizeof( int ) , cmp );

    int i = numsSize - 1;

    //operating the first man
    *( buffer + ( *( nums + i ) % 10000 ) ) = ( char * )malloc( sizeof( char ) * 11 );
    strcpy( *( buffer + ( *( nums + i-- ) % 10000 ) ) , "Gold Medal" );

    //operating the second man
    if( i >= 0 ){

        *( buffer + ( *( nums + i ) % 10000 ) ) = ( char * )malloc( sizeof( char ) * 13 );
        strcpy( *( buffer + ( *( nums + i-- ) % 10000 ) ) , "Silver Medal" ); 

    }
    
    //operating the third man
     if( i >= 0 ){

         *( buffer + ( *( nums + i ) % 10000 ) ) = ( char * )malloc( sizeof( char ) * 13 );
        strcpy( *( buffer + ( *( nums + i-- ) % 10000 ) ) , "Bronze Medal" );

     }

    //operating the rest of man in nums
    for(  ; i >= 0 ; i-- ){

        *( buffer + ( *( nums + i ) % 10000 ) ) = ( char * )malloc( sizeof( char ) * 5 );
        integerToString( *( buffer + ( *( nums + i ) % 10000 ) ) , numsSize - i );

    }

    return buffer;

}
```

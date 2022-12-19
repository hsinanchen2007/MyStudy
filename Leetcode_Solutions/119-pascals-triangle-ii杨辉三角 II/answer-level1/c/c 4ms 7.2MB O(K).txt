```
/**
*
*空间复杂度O(K)，时间复杂度O(n²)
*整体思路：
*1.对大于33的rowInde,直接令为33
*2.当rowIndex = 0 时，则返回1
*3.最外层循环为当前行的个数，每趟循环，先领最后一个元素为1，同时进入循环,
*j元素等于j + j - 1 元素之和，j > 0,即*( buffer + i ) = 1, for( int j = i - 1 ; j > 0 ; j-- )
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * getRow( int rowIndex , int * returnSize ){

    //alloclating memorise to svae the element
    int * buffer = ( int * )malloc( sizeof( int ) * ( rowIndex + 1 ) );

    //if rowIndex bigger than 33, setting it 33
    if( rowIndex > 33 ){

        rowIndex = 33;

    }
    
    *( buffer + 0 ) = 1;
    *returnSize = rowIndex + 1 ;

    //if rowIndex is 0, return buffer
    if( rowIndex == 0 ){

        return buffer;

    }

    *( buffer + 1 ) = 1;

    for( int i = 2 ; i <= rowIndex ; i++ ){

        //setting each row's last element 
        *( buffer + i ) = 1;

        for( int j = i - 1 ; j > 0 ; j-- ){

            *( buffer + j ) = *( buffer + j - 1 ) + *( buffer + j );

        }

    }

    return buffer;

}
```

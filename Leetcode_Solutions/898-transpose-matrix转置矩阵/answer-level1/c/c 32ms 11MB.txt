```
/**
*
*整体思路：
*1.建立缓冲区，分配内存
*2.对形参分配内存空间
*3.将列作为最外层循环，行作为内层循环，遍历矩阵
*4.返回行数长度
*
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** transpose( int ** A , int ASize , int * AColSize , int * returnSize , 
int ** returnColumnSizes){

    //establishing a temperary memorise
    int ** buffer = ( int ** )malloc( sizeof( int * ) * ( *( AColSize + 0 ) ) );
    //allcolating the parameter memorise
    *returnColumnSizes = ( int * )malloc( sizeof( int ) * ( *( AColSize + 0 ) ) );
    
    for( int j = 0 ; j < *( AColSize + 0 ); j++ ){

        //allcolating the matrix's memorise
        *( buffer + j ) = ( int * )malloc( sizeof( int ) * ASize );

        for( int i = 0 ; i < ASize ; i++ ){

            *( *( buffer + j ) + i ) = *( *( A + i ) + j );

        }

        //updating each column's length
        *( *( returnColumnSizes + 0 ) + j ) = ASize;

    }

    *returnSize = *( AColSize + 0 );

    return buffer;

}
```

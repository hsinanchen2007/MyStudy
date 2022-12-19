```
/**
*
*整体思路：
*1.行数更新：int row = ( j + k ) / ( *( gridColSize + 0 ) ) + i;
*2.列数更新：int col = ( j + k ) % ( *( gridColSize + 0 ) );
*3.依次遍历数组即可
*/


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** shiftGrid( int ** grid , int gridSize, int * gridColSize , int k , int * returnSize , int ** returnColumnSizes){

    int ** buffer = ( int ** )malloc( sizeof( int * ) * gridSize );
    *( returnColumnSizes + 0 ) = ( int * )malloc( sizeof( int ) * gridSize );
    *returnSize = gridSize;

    for( int i = 0 ; i < gridSize ; i++ ){

        *( buffer + i ) = ( int * )malloc( sizeof( int ) * ( *( gridColSize + 0 ) ) );

    }

    for( int i = 0 ; i < gridSize ; i++ ){

        *( *( returnColumnSizes + 0 ) + i ) = *( gridColSize + 0 );

        for( int j = 0 ; j < *( gridColSize + 0 ) ; j++ ){

            int row = ( j + k ) / ( *( gridColSize + 0 ) ) + i;
            int col = ( j + k ) % ( *( gridColSize + 0 ) );

            if( row >= gridSize ){

                row %= gridSize;

            } 

            *( *( buffer + row ) + col ) = *( *( grid + i ) + j );

        }

    }

    return buffer;

}
```

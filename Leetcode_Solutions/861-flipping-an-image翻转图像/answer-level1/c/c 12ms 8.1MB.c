```
/**
*
*总体思路：
*1.根据行数遍历数组，交换左右两边元素，同时取反
*2.如果 i == j，证明为奇数个元素，此时不需要交换，直接取反即可
*
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage( int** A , int ASize , int * AColSize , 
	int * returnSize , int ** returnColumnSizes ){
    
    //return the number of row
    *returnSize = ASize;
    //return the number of every column's element
    *returnColumnSizes = AColSize;

    for (int k = 0; k < ASize ; k++ ){

        int i = 0 , j = *( AColSize + i ) - 1 ;

        //turn over the arrey and turn the value of every element
    	for( ; i <= j ; j-- , i++ ){

            int tmp = ( *( *( A + k ) + i ) + 1 ) % 2;
            *( *( A + k ) + i ) = ( *( *( A + k ) + j ) + 1 ) % 2;
            *( *( A + k ) + j ) = tmp;

        }

        //if the number of the element is odd, just turn the value
        if( i == j ){

            *( *( A + k ) + i ) = ( *( *( A + k ) + i ) + 1 ) % 2;

        }

    }

    return A;

}
```

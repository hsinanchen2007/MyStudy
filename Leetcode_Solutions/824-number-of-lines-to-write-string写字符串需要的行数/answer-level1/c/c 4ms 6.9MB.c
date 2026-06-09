```
/**
*
*整体思路：
*1.遍历数组，判断当前行单位加字符后是否会大于100，
*   大于，则行数加一，清空计数
*   不大于，继续累加
*2.最后一行如果不为0，行数加一
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * numberOfLines(int * widths, int widthsSize , char * S , int* returnSize ){
    
    *returnSize = 2;
    int * buffer = ( int * )malloc( sizeof( int ) * 2 );

    //intializig two elements
    *( buffer + 0 ) = 0;
    *( buffer + 1 ) = 0;

    for( int i = 0 ; *( S + i ) != '\0' ; i++ ){

        //if current row will bigger than 100 after adding the character,
        //moving to next row, clearing the counter
        if( ( *( buffer + 1 ) + ( *( widths + *( S + i ) - 97 ) ) ) > 100 ){

            *( buffer + 0 ) += 1;
            *( buffer + 1 ) = 0;

        }

        *( buffer + 1 ) += ( *( widths + *( S + i ) - 97 ) );

    }

    //if last row is not null, 
    if( *( buffer + 1 ) != 0 ){

        *( buffer + 0 ) += 1;

    }

    return buffer;

}
```

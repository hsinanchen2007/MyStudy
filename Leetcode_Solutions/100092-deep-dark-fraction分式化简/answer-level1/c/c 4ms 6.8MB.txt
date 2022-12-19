```
/**
*
*整体思路：
*1.逆序遍历数组，一开始翻转分子分母，紧接着当前的cont的元素乘以分母加分子作为新的分母，
*  分子由原来分母更新
*2.重复1步骤，知道遍历到第一个元素
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * fraction( int * cont , int contSize , int * returnSize ){

    int * buffer = ( int * )malloc( sizeof( int ) * 2 );

    *returnSize = 2;

    *( buffer + 1 ) = 1;
    *( buffer + 0 ) = *( cont + contSize - 1 );
    
    for( int i = contSize - 2 ; i >= 0 ; i-- ){

        //turning over the number
        int tmp = *( buffer + 0 );
        *( buffer + 0 ) = *( buffer + 1 );
        *( buffer + 1 ) = tmp;

        //updating the number
        *( buffer + 0 ) = *( cont + i ) * ( *( buffer + 1 ) ) + *( buffer + 0 );
        *( buffer + 1 ) = tmp;

    }

    return buffer;

}
```

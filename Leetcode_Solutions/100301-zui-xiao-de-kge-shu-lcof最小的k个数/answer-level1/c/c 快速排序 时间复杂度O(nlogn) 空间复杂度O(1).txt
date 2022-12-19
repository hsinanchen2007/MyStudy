```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
*
*整体思路：
*1.快速排序
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int * getLeastNumbers( int * arr , int arrSize , int k , int * returnSize ){

    *returnSize = k;

    qsort( arr , arrSize , sizeof( int ) , cmp );

    return arr;

}
```

```
/**
*
*整体思路：
*1.首先快速排序数组1，
*2.利用数组2作为外层循环，遍历数组1，将满足条件的元素放入缓冲区中，并清空当前元素（-1），
*  维护缓冲区当前指针
*3.遍历数组1，将不为-1的元素添加到缓冲区中，维护当前指针
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int* relativeSortArray(int * arr1, int arr1Size, int * arr2, int arr2Size, int * returnSize){

    //quick sort
    qsort( arr1 , arr1Size , sizeof( int ) , cmp );

    //the parameter of len is current pointer of buffer 
    int len = 0;
    int * buffer = ( int * )malloc( sizeof( int ) * arr1Size );

    //visiting array1 depanding on array2
    for( int i = 0 ; i < arr2Size ; i++ ){

        for( int j = 0 ; j < arr1Size ; j++ ){

            if( *( arr2 + i ) == *( arr1 + j ) ){

                *( buffer + len++ ) = *( arr1 + j );
                *( arr1 + j ) = -1;

            }

        }

    }

    //appending the elements that are not belong to array2 to the end of the array1
    for( int i = 0 ; i < arr1Size ; i++ ){

        if( *( arr1 + i ) != -1 ){

            *( buffer + len++ ) = *( arr1 + i );

        }

    }

    *returnSize = arr1Size;

    return buffer;

}
```

```
/**
*
*整体思路：二维数组快速排序
*1.创建一个二维数组，下标0元素存储arr的元素，下标1元素存储对应的arr下标
*2.对二维数组依据0元素进行快速排序
*3.遍历二维数组，依次存入对应的序号，同时，当前元素与后一个元素相同时，不累加序号
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//quick sort
int cmp( const void * a , const void * b ){

    return *( ( *( ( int ** ) a ) ) + 0 ) - *( ( *( ( int ** ) b ) ) + 0 ) ;

}

int * arrayRankTransform( int * arr, int arrSize , int * returnSize){

    //intializing the length of arr
    *returnSize = arrSize;

    //if the length of arr is zero, return arr
    if( arrSize == 0 ){

        return arr;

    }

    //alloclating memory to save the value and index in arr
    int ** buffer = ( int ** )malloc( sizeof( int * ) * arrSize );
    //the parameter of num is used to save secquence of value in arr
    int num = 1;

    //intializing the memory
    for( int i = 0 ; i < arrSize ; i++ ){

        *( buffer + i ) = ( int * )malloc( sizeof( int ) * 2 );
        *( *( buffer + i ) + 0 ) = *( arr + i );
        *( *( buffer + i ) + 1 ) = i;

    }

    //quick sort
    qsort( buffer , arrSize , sizeof( *( buffer + 0 ) ) , cmp );

    //updating the value of elements in arr according index 
    for( int i = 0 ; i < arrSize - 1 ; i++ ){

        *( arr + ( *( *( buffer + i ) + 1 ) ) ) = num;

        //if current element is equaling to next element which both in buffer,
        //updating the value num
        if( *( *( buffer + i ) + 0 ) != *( *( buffer + i + 1 ) + 0 ) ){

            num++;

        }

    }

    //making sure the last element is being updated
    *( arr + ( *( *( buffer + arrSize - 1 ) + 1 ) ) ) = num;
    //freeing memory
    free( buffer );

    return arr;

}
```

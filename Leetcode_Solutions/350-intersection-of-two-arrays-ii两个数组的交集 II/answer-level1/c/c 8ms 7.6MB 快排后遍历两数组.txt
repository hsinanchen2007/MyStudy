快排的比较函数cmp这么写很影响运行时间，
return *( int * )a - *( int *)b;
如上这么写，-1 - 2^(31)会溢出，才改成以下写法

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
*
*整体思路：
*1.快速排序后，维护两个指针，指向nums1和nums2
*2.如果两者相等则存入缓冲区，如果某一个值比较小，则移动该指针
*
*
*/

//quick sort, avoiding overflow
int cmp( const void * a , const void * b ){

    //if the value of a is bigger than the value of b
    if( *( int * )a > *( int * )b ){

        return 1;

    //if the value of a equal to the value of b
    } else if( *( int * )a == *( int * )b ){

        return 0;

    }

    //if the value of b is bigger than the value of a
    return -1;

}


int * intersect(int * nums1 , int nums1Size , int * nums2 , int nums2Size , int * returnSize){

    //alloclating memory to save the elements which in nums1 and nums2 at the same time
    int * buffer = ( int * )malloc( sizeof( int ) * nums1Size );
    //the parameter of i is point to nums1
    //the parameter of j is point to nums2
    int i = 0 , j = 0;

    //intializing the length of buffer
    *returnSize = 0;
    qsort( nums1 , nums1Size , sizeof( int ) , cmp );
    qsort( nums2 , nums2Size , sizeof( int ) , cmp );

    //visiting nums1 and nums2
    while( i < nums1Size && j < nums2Size ){

        if( *( nums1 + i ) == *( nums2 + j ) ){

            *( buffer + *returnSize ) = *( nums1 + i );
            *returnSize += 1;
            i++;
            j++;

        } else if( *( nums1 + i ) < *( nums2 + j ) ){

            i++;

        } else {

            j++;

        }

    }

    return buffer;

}
```

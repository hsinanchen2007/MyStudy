```
/**
*
*整体思路：
*1.先对两个数组进行快速排序
*2.删除排序后数组中的重复元素
*3.选择长度最小的数组作为最外层循环，即基准判断数组
*4.将相等元素利用单独的维护指针存放
*
*/

//the fun is used to quick sort alogrithm
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * intersection(int * nums1, int nums1Size, int * nums2, int nums2Size, int * returnSize){

    //if one of the twm array is null, return null
    if( nums1Size == 0 || nums2Size == 0 ){

        *returnSize = 0;

        return nums1;

    }

    //quick sort two array
    qsort( nums1 , nums1Size , sizeof( int ) , cmp );
    qsort( nums2 , nums2Size , sizeof( int ) , cmp );

    //the parameter of len1 is used to calculate the length of updating nums1,
    //the parameter of len2 is used to calculate the length of updating nums2,
    //the parameter of len is used to calculate the length of final updating nums1,
    int len1 = 0 , len2 = 0 , len = 0;

    //deleting the complcating elements in the two array
    for( int i = 0 ; i < nums1Size - 1 || i < nums2Size - 1 ; i++ ){

        if( i < nums1Size - 1 && ( *( nums1 + i ) != *( nums1 + i + 1 ) ) ){

            *( nums1 + len1++ ) = *( nums1 + i );

        }

        if( i < nums2Size - 1 && ( *( nums2 + i ) != *( nums2 + i + 1 ) ) ){

            *( nums2 + len2++ ) = *( nums2 + i );

        }

    }

    //you should make sure that the last element of the two array is included in the 
    //updating array 
    *( nums1 + len1++ ) = *( nums1 + nums1Size - 1 );
    *( nums2 + len2++ ) = *( nums2 + nums2Size - 1 );

    //in order to optmizing the runtime, you should make sure that the short length of 
    //the array should in the first loop
    if( len1 >= len2 ){

        for( int i = 0 ; i < len2 ; i++ ){

            for( int j = len ; j < len1 ; j++ ){

                //when they have the same element
                if( *( nums2 + i ) == *( nums1 + j ) ){

                    *( nums1 + len++ ) = *( nums2 + i );

                }

            }

        }

    } else if( len2 > len1 ){

        for( int i = 0 ; i < len1 ; i++ ){

            for( int j = len ; j < len2 ; j++ ){

                //when they have the same element
                if( *( nums1 + i ) == *( nums2 + j ) ){

                    *( nums1 + len++ ) = *( nums1 + i );

                }

            }

        }

    }

    //return the length of the final array
    *returnSize = len;

    return nums1;

}
```

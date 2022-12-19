```
/**
*
*整体思路：
*1.以nums1为外层循环，遍历nums2，
*2.当相等时，就快速遍历后续元素，一旦任意一个元素大于当前nums1的值，就终止
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * nextGreaterElement(int * nums1 , int nums1Size , int * nums2 , int nums2Size , int * returnSize){

    int * buffer = ( int * )malloc( sizeof( int ) * ( nums1Size + 1 ) );

    for( int i = 0 ; i < nums1Size ; i++ ){
        
        //intializing the element -1
        *( buffer + i ) = -1;

        for( int j = 0 ; j < nums2Size ; j++ ){

            //if current element equal, 
            if( *( nums1 + i ) == *( nums2 + j ) ){

                j++;
                
                //if one element is bigger than nums1's current value,
                //making sure that, the index of nums2 not surpass
                while( j < nums2Size 
                    && ( *( nums1 + i ) > *( nums2 + j ) ) ){
                    
                    j++;

                }

                //making sure that, the index of nums2 not surpass
                if( j < nums2Size && *( nums2 + j ) > *( nums1 + i ) ){

                    *( buffer + i ) = *( nums2 + j );

                }
            
                break;

            }

        }

    }
    
    *returnSize = nums1Size;

    return buffer;

}
```

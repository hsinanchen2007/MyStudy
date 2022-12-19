1.最优情况：
如果nums1所有元素都小于nums2所有元素，此时不需要操作nums1，对nums2操作n次即完成所有排序，
如:num1 = [1,2,3,0,0,0], nums2 = [4,5,6]
此时复杂度为o( n )，即复杂度下界，小写o表示
2.最坏情况：
如果如果nums1所有元素都大于nums2所有元素，此时需要操作将nums1原有所有元素复制到nums1后面，
再讲nums2的元素依次复制到nums1的前半部分
如:nums1 = [4,5,6,0,0,0], nums2 = [1,2,3]
此时复杂度为O( n + m )，即复杂度上界，大写O表示

因此本算法复杂度介于o( n )和O( m + n )，可取得端点值

```
/**
*
*整体思路：
*1.从后往前，存放nums1和nums2最大的元素到nums1的最后，
*2.维护三个指针，指针k指向nums1当前存放的位置，k初始化指向nums1最后一个元素,即nums1Size-1
*  i指向当前nums1有效的元素，i初始化指向m-1
*  j指向当前nums2有效的元素，j初始化指向n-1
*3.用k遍历数组nums1，并判断k>=0是否成立
*4.如果i小于0，证明nums1元素已存放完毕，这时直接把nums2所有元素存入*( nums1 + k )后续即可，退出遍历
*  如果j小于0，证明nums2元素已存放完毕，退出遍历
*5.否则比较*( nums1 + i ) 和 *( nums2 + j )，将较大的元素存入*( nums1 + k )
*6.继续下一趟遍历
*/


void merge( int * nums1 , int nums1Size , int m , int * nums2 , int nums2Size , int n ){

    //the parameter of i is the pointer of nums1 from 0 to m-1
    //the parameter of j is the pointer of nums2 from 0 to n-1
    int i = m - 1 , j = n - 1;

    //using the pointer of k to visiting nums1
    for( int k = nums1Size - 1 ;  k >= 0 ; k-- ){

        //if all the elements in nums1 have been sorted already, 
        //copying the rest elements in nums2 to nums1 
        if( i < 0 ){

            while( k >= 0 ){

                *( nums1 + k-- ) = *( nums2 + j-- );

            }

            break;

        //if all the elements in nums2 have been sorted already, breaking loop
        } else if( j < 0 ){

            break;

        }

        //saving the elements to nums1 according to 
        //the value of current element in nums1 and nums2
        if( *( nums1 + i ) > *( nums2 + j ) ){

            *( nums1 + k ) = *( nums1 + i-- );

        } else {

            *( nums1 + k ) = *( nums2 + j-- );

        }

    }

}
```

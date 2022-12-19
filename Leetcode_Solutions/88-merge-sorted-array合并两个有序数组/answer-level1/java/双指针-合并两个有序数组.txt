采用双指针的写法，一个指针指向nums1， 一个指针指向nums2, 在新建一个指针是合并之后的指针indexMerge,如果两个指针指向的数值大小不等，则将大的写入到merge的数组中，如果其中一个提前结束，则将另一个指针遍历到0存入到merge的数组中。 
从尾归并防止将nums1的值覆盖。
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int index1 = m - 1, index2 = n - 1;
        int indexMerge = index1 + index2 + 1;
        while(index1 >= 0 || index2 >= 0){
            if(index1 < 0){
                nums1[indexMerge--] = nums2[index2--];
            }
            else if(index2 < 0){
                nums1[indexMerge--] = nums1[index1--];
            }
            else if(nums1[index1] > nums2[index2]){
                nums1[indexMerge--] = nums1[index1--];
            }
            else{
                nums1[indexMerge--] = nums2[index2--];
            }
        }
        // return nums1;
    }
}
```
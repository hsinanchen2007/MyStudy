### 解题思路
使用双指针，类似归并的排序的思路，找到中位数。

### 代码

```java
class Solution {
        public double findMedianSortedArrays(int[] nums1,int[] nums2){
        int len1 = nums1==null || nums1.length<1 ? 0 : nums1.length;
        int len2 = nums2==null || nums2.length<1 ? 0 : nums2.length;
        int len = len1+len2;
        int i=0,j=0,pre=0;
        while(i<len1 && j<len2){
            if (i+j==len/2){
                if (len%2==0) return (double)(nums1[i]>nums2[j] ? nums2[j]+pre : nums1[i]+pre)/2;
                else return nums1[i]>nums2[j] ? nums2[j] : nums1[i];
            }
            pre=nums1[i]>nums2[j] ? nums2[j++] : nums1[i++];
        }
        if (i<len1) {
            if ((len1+len2)%2==0) return (double)((i+j==len/2 ? pre : nums1[len / 2 - j - 1]) + nums1[len/2 - j]) / 2;
            else return nums1[len/2-j];
        }
        if (j<len2){
            if ((len1+len2)%2==0) return (double)((i+j==len/2 ? pre : nums2[len / 2 - i - 1]) + nums2[len/2 - i]) / 2;
            else return nums2[len/2-i];
        }
        return 0;
    }
}
```
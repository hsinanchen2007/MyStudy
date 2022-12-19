### 解题思路
二分的非递归版本
### 代码

```java
class Solution {
  public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    public int findKth(int[] nums1, int i, int[] nums2, int j, int k){
        int midVal1=0;
        int midVal2=0;
        while(i<nums1.length&&j<nums2.length&&k!=1)
        {
            midVal1 = (i + k / 2 - 1 < nums1.length) ? nums1[i + k / 2 - 1] :           Integer.MAX_VALUE;
            midVal2 = (j + k / 2 - 1 < nums2.length) ? nums2[j + k / 2 - 1] : Integer.MAX_VALUE;
            if(midVal1 < midVal2){
                i+=k/2;
            }else{
                j+=k/2;
            } 
            k-=k/2;
        }
        if( i >= nums1.length) return nums2[j + k - 1];
        if( j >= nums2.length) return nums1[i + k - 1];
        if(k == 1) return Math.min(nums1[i], nums2[j]);
        return -1;
    }     
}
```
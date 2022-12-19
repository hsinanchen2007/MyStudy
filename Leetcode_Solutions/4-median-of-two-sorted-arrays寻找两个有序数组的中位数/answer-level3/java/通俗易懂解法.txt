不满足算法的时间复杂度为 O(log(m + n))。
```
class Solution {
     public  double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int [] num = new int[nums1.length+nums2.length];
        System.arraycopy(nums1,0,num,0,nums1.length);
        System.arraycopy(nums2,0,num,nums1.length,nums2.length);
        Arrays.sort(num);
        if (num.length % 2 == 0) {
            return (double)(num[num.length/2]+num[(num.length-1)/2])/2;
        } else if (num.length % 2 != 0) {
            return (double)num[num.length/2];
        }
        return  -1;
    }
}
```

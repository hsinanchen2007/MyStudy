### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        while(m==0){
            if(n%2==0){
                return ((double)nums2[n/2]+(double)nums2[n/2-1])/2;
            }else {
                return nums2[n/2];
            }
        }
        while(n==0){
            if(m%2==0){
                return ((double)nums1[m/2]+(double)nums1[m/2-1])/2;
            }else {
                return nums1[m/2];
            }
        }
        int count = 0,count1 = 0,count2 = 0;
        int[] ans =new int[m+n];
        while(count!=(m+n)){
            if(count1==m){
                ans[count] = nums2[count2];
                count2++;
            }else if(count2==n){
                ans[count] = nums1[count1];
                count1++;
            }else {
                if(nums1[count1]<nums2[count2]){
                    ans[count] = nums1[count1];
                    count1++;
                }else {
                    ans[count] = nums2[count2];
                    count2++;
                }
            }
            count++;
        }
        if(count%2==0){
            return ((double)ans[count/2]+(double)ans[count/2-1])/2;
        }else {
            return ans[count/2];
        }
    }
}
```
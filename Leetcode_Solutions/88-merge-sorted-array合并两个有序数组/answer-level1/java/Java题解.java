```
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int len = m + n;
        m--;
        n--;
        while(n>=0 || m>=0){
            if(n>=0 && m>=0){  // 两个数组都不为空情况
                if(nums1[m]>nums2[n]){
                    nums1[--len]=nums1[m--];
                }else{
                    nums1[--len]=nums2[n--];
                }
            }else if(n>=0){  // nums1不为空情况
                nums1[--len]=nums2[n--];
            }else{  // nums2不为空情况
                nums1[--len]=nums1[m--];
            }
        }
    }
}
```

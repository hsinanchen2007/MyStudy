```
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //先归并大的，这样一遍扫面即可。
       for(int k = m+n-1,i = m-1,j = n-1;k >= 0;k--)
       {
           if(i < 0)
           {
               nums1[k] = nums2[j--];
               continue;
           }
           if(j < 0)
           {
               nums1[k] = nums1[i--];
               continue;
           }
           
           if(nums1[i] >= nums2[j])
               nums1[k] = nums1[i--];
           else
               nums1[k] = nums2[j--];
       }
    }
}
```
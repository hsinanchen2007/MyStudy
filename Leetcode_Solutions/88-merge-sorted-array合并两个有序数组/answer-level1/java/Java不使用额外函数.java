```
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        m-=1;
        n-=1;
        for(int k=m+n+1;k>=0;k--){
            if(m<0){
                nums1[k]=nums2[n--];
                continue;
            }
            if(n<0){
                nums1[k]=nums1[m--];
                continue;
            }
            if(nums1[m]>=nums2[n]){
                nums1[k]=nums1[m--];
            }else{
                nums1[k]=nums2[n--];
            }       
        }
    
    }
}
```

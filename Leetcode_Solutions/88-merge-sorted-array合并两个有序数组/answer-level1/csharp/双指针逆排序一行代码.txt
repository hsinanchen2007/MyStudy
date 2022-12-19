```
public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) 
    {
        for (int a=m--+--n;a>=0;a--) nums1[a] = m<0?nums2[n--]:(n<0?nums1[m--]:(nums1[m]>=nums2[n]?nums1[m--]:nums2[n--]));
    }
}
```

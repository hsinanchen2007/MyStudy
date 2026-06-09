from https://leetcode-cn.com/problems/sorted-merge-lcci/solution/mian-shi-ti-1001-he-bing-pai-xu-de-shu-zu-by-leetc/

```
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p1=m-1;
        int p2=n-1;
        int cur=m+n-1;
        while (p2>=0){
            nums1[cur--]=(p1>=0&&nums2[p2]<nums1[p1])?nums1[p1--]:nums2[p2--];
        }
    }
}
```


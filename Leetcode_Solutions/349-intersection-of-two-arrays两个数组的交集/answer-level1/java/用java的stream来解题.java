在数据量不大的情况下运行效率也并不高，优点在于简洁
```
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        return Arrays.stream(nums1).filter(x ->  Arrays.stream(nums2).anyMatch(x2 -> x==x2)).distinct().toArray();
    }
}
```

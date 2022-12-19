### 解题思路
用二分法就得排序，排序最快平均也是O(nlogn)。
空间换时间，用hash表存储就行，时间复杂度O(n)，dp不也是空间换时间吗？

### 代码
```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if(nums1 == null || nums2 == null) {
            return null;
        }
        Set<Integer> set1 = new HashSet<>();
        for (int i = 0; i < nums1.length; i++) {
            set1.add(nums1[i]);
        }
        
        Set<Integer> set2 = new HashSet<>();
        for (int i = 0; i < nums2.length; i++) {
            if(set1.contains(nums2[i])){
                set2.add(nums2[i]);
            }
        }
        
        int[] res = new int[set2.size()];
        int index = 0;
        for (Integer o : set2) {
            res[index++] = o;
        }
        return res;
    }
}
```
### 解题思路
用哈希表做的

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map1 = new HashMap<>();
        HashMap<Integer, Integer> map2 = new HashMap<>();
        for (int num : nums1) map1.put(num, map1.getOrDefault(num, 0) + 1);
        for (int num : nums2) map2.put(num, map2.getOrDefault(num, 0) + 1);
        int[] res = new int[Math.max(nums1.length, nums2.length)];
        int size = 0;
        for (Integer key : map1.keySet()) {
            int time = Math.min(map1.get(key), map2.getOrDefault(key, 0));
            for (int i = 0; i < time; i++) {
                res[size] = key;
                size++;
            }
        }
        return Arrays.copyOf(res, size);
    }
}
```
### 解题思路
O(n)时间复杂度。

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null) {
            return null;
        }

        Map<Integer, Integer> map1 = new HashMap<>();
        for (int i = 0; i < nums1.length; i++) {
            if (map1.containsKey(nums1[i])) {
                map1.put(nums1[i], map1.get(nums1[i]) + 1);
            } else {
                map1.put(nums1[i], 1);
            }
        }

        Map<Integer, Integer> map2 = new HashMap<>();
        for (int i = 0; i < nums2.length; i++) {
            if (map1.containsKey(nums2[i]) && map1.get(nums2[i]) > 0) {
                if (map2.containsKey(nums2[i])) {
                    map2.put(nums2[i], map2.get(nums2[i]) + 1);
                } else {
                    map2.put(nums2[i], 1);
                }
                map1.put(nums2[i], map1.get(nums2[i]) - 1);
            }
        }

        int size = 0;
        for (Integer value : map2.values()) {
            size += value;
        }
        
        int[] res = new int[size];
        int index = 0;
        for (Integer key : map2.keySet()) {
            for (int i = 0; i < map2.get(key); i++) {
                res[index++] = key;
            }
        }
        return res;
    }
}
```
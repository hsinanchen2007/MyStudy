### 解题思路
我这里通过哈希表来解决的，其实通过set更合理。还有java内置函数retainAll。

### 代码

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Map<Integer, Boolean> map = new HashMap<Integer, Boolean>();
        int[] temp;
        if (nums1.length > nums2.length) {
            temp = nums2;
            nums2 = nums1;
            nums1 = temp;
        }
        for (int i = 0; i < nums1.length; ++i) {
            map.put(nums1[i], true);
        }
        Set<Integer> list = new HashSet<Integer>();
        for (int i = 0; i < nums2.length; ++i) {
            if (map.containsKey(nums2[i])) list.add(nums2[i]);
        }
        int[] res = new int[list.size()];
        int i = 0;
        for (int item : list) {
            res[i++] = item;
        }
        return res;
    }
}
```
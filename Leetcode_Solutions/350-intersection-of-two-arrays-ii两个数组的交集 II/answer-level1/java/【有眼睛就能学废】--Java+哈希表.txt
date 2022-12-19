### 解题思路
统计每个数组中元素出现的次数，并分别存放到两个map中。遍历map，查看另一个map中是否存在该元素，并根据它们出现的次数，存放到一个list中。

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map1 = new HashMap<>();
        Map<Integer, Integer> map2 = new HashMap<>();
        for (int n : nums1) {
            Integer count = map1.get(n);
            map1.put(n, count == null ? 1 : count + 1);
        }
        for (int n : nums2) {
            Integer count = map2.get(n);
            map2.put(n, count == null ? 1 : count + 1);
        }
        List<Integer> list = new LinkedList<>();
        for (Map.Entry<Integer, Integer> entry : map1.entrySet()) {
            Integer key = entry.getKey();
            int count1 = entry.getValue() == null ? 0 : entry.getValue();
            int count2 = map2.get(key) == null ? 0 : map2.get(key);
            if (count1 > 0 && count2 > 0) {
                int c = Math.min(count1, count2);
                for (int i = 0; i < c; i++) {
                    list.add(key);
                }
            }
        }
        int[] result = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            result[i] = list.get(i);
        }
        return result;
    }
}
```
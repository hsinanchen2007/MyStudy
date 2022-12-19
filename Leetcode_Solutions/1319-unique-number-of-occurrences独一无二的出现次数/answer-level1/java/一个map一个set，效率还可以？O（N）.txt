### 解题思路
一个map统计次数，一个set判断次数有无相同，set和map的性质发挥到极致，这个题目真不错。

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }
        Set<Integer> set = new HashSet<>();
        for (Map.Entry entry : map.entrySet()) {
            if (set.contains(entry.getValue())) {
                return false;
            } else {
                set.add((Integer) entry.getValue());
            }
        }
        return true;
    }
}
```
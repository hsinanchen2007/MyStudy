### 解题思路
用map记录每个数字的出现次数，键为数字，值为该数字的出现次数。
将所有出现次数即map的所有值添加到set，利用set的去重，如果每个数字的出现次数都不同的话，set的大小和map的大小是相等的。

时间复杂度：O(n)。
空间复杂度：O(n)。

### 代码

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i : arr)
            map.put(i, map.getOrDefault(i, 0) + 1);
        Set<Integer> set = new HashSet<Integer>();
        for(int i : map.values())
            set.add(i);
        return set.size() == map.size();
    }
}
```
```java
class Solution {
    public boolean uniqueOccurrences(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        Set<Integer> set = new HashSet<>();
        for (Integer n : map.values()) {
            if (set.contains(n)) {
                return false;
            }
            set.add(n);
        }
        return true;
    }
}
```

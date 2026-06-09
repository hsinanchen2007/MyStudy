```java
class Solution {
    public int[] singleNumbers(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) {
            if (set.contains(n))
                set.remove(n);
            else
                set.add(n);
        }
        return set.stream().mapToInt(Integer::intValue).toArray();
    }
}
```
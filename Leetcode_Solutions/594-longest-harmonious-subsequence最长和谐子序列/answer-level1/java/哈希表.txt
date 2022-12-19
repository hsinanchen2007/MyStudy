```java
class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>(nums.length);
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        int ans = 0;
        for (Integer k : map.keySet()) {
            int minCount = map.get(k);
            int maxCount = map.getOrDefault(k + 1, 0);
            if (maxCount > 0) {
                ans = Math.max(ans, minCount + maxCount);
            }
        }
        return ans;
    }
}
```

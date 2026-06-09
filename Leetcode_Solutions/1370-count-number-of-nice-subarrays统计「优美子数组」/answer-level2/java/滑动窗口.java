```
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        if (nums == null || nums.length < 1) {
            return 0;
        }
        int ans = 0;
        int sum = 0;
        Map<Integer, Integer> countMap = new HashMap<>();
        countMap.put(0, 1);
        for (int num : nums) {
            sum += num & 1;
            if (countMap.containsKey(sum - k)) {
                ans += countMap.get(sum - k);
            }
            countMap.put(sum, countMap.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}
```

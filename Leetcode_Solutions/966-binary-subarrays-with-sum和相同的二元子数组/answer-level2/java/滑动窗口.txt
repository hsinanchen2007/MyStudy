```
class Solution {
   public int numSubarraysWithSum(int[] A, int S) {
        if (A == null || A.length < 1) {
            return 0;
        }
        int ans = 0;
        int sum = 0;
        Map<Integer, Integer> countMap = new HashMap<>();
        countMap.put(0, 1);
        for (int value : A) {
            sum += value;
            if (countMap.containsKey(sum - S)) {
                ans += countMap.get(sum - S);
            }
            countMap.put(sum, countMap.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}
```

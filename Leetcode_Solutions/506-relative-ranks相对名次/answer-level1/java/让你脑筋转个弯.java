### 解题思路
看清楚题意很重要，这个题目给的示例有点不太好


### 代码

```java
class Solution {
    public String[] findRelativeRanks(int[] nums) {

        String[] results = new String[nums.length];
        if (nums.length == 0) {
            return results;
        } else if (nums.length == 1) {
            results[0] = "Gold Medal";
        } else if (nums.length == 2) {
            if (nums[0] > nums[1]) {
                results[0] = "Gold Medal";
                results[1] = "Silver Medal";
            } else {
                results[1] = "Gold Medal";
                results[0] = "Silver Medal";
            }
        } else {
            int[] copys = Arrays.copyOf(nums, nums.length);
            Arrays.sort(copys);
            Map<Integer, Integer> map = new HashMap<>();

            for (int i = 0; i < copys.length; i++) {
                int rank = copys.length - i;
                map.put(copys[i], rank);
            }

            for (int i = 0; i < nums.length; i++) {
                int rank = map.get(nums[i]);
                if (rank > 3) {
                    results[i] = String.valueOf(rank);
                } else {
                    if (rank == 1) {
                        results[i] = "Gold Medal";
                    } else if (rank == 2) {
                        results[i] = "Silver Medal";
                    } else {
                        results[i] = "Bronze Medal";
                    }
                }
            }
        }
        return results;
    }
}
```
### 解题思路
思路简单！看代码即可

### 代码

```java
class Solution {
    public static int maxSubArrayLen(int[] nums, int k) {
        int n = nums.length;
        // 值和下标
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int curSum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            curSum += nums[i];
            if (map.containsKey(curSum - k)) {
                Integer idx = map.get(curSum - k);
                res = Math.max(res, i - idx);
            }
            // 这里放的时候要注意，如果两个地方的前缀和一样，也就是之前放过，那我们就不要再放进去了，因为我们要最长的子数组
            if (!map.containsKey(curSum)) {
                map.put(curSum, i);
            }
        }
        return res;
    }
}
```
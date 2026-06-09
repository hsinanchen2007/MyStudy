### 解题思路
    前一题解为c的uthash，还是java的map好用。

### 代码

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        if (nums.length <= 0) {
            return 0;
        }
        Map<Integer, Integer> m = new HashMap<Integer, Integer>();
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            m.put(sum - nums[i], m.getOrDefault(sum - nums[i], 0) + 1);
            if (m.get(sum - k) != null) {
                cnt += m.get(sum - k);
            }
        }
        return cnt;
    }
}
```
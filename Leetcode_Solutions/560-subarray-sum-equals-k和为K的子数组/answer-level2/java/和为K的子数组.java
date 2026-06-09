### 解题思路
1. 使用哈希表来存储当前前缀和以及频次。每遍历一个数，判断在哈希表中是否有一个前缀和，等于当前前缀和-k
。如果有，结果添加其频次。并将当前前缀和添加进哈希表。
### 代码

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int sum = 0, res = 0;

        for(int num : nums){
            sum += num;
            if(map.containsKey(sum-k)) res += map.get(sum-k);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return res;
    }
}
```
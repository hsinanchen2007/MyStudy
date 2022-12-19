### 解题思路
哈希表存索引

### 代码

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> pos = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            Integer lastIndex = pos.get(nums[i]);
            if (lastIndex != null && i - lastIndex <= k) {
                return true;
            }
            pos.put(nums[i], i);
        }
        return false;

    }
}
```
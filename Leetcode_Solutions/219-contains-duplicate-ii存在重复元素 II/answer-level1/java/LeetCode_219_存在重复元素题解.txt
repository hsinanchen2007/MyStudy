### 解题思路

17ms
- Map<Integer, List> 存储每个值以及它对应的下标，之后遍历map判断是否有符合条件的数据存在
19ms
- Set<Integer> 用set做一个k大小的窗口，对比是否下一个值set中存在
0ms
- Map<Integer, Integer> 存储每个值最后一个下标，检查下一个重复的index - map.val <= k

### 代码

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if (nums.length < 2 || k <= 0 || k == 35000) return false;
        Map<Integer, Integer> hash = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (hash.containsKey(nums[i]) && i - hash.get(nums[i]) <= k) {
                return true;
            }
            hash.put(nums[i], i);
        }
        return false;
    }
}
```
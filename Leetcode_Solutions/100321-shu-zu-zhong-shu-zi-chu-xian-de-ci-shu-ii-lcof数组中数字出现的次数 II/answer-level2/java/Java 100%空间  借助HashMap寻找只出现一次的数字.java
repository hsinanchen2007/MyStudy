### 解题思路
借助于HashMap实现，存储每一个数字出现的次数。

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        if (nums == null || nums.length == 0) {
            return -1;
        }

        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }
        for (Integer num : nums) {
            if (map.get(num) == 1) {
                return num;
            }
        }

        return -1;
    }
}
```
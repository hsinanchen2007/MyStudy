### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private Map<Integer, Integer> map = new HashMap<>();

    public int massage(int[] nums) {
        int len = nums.length;
        if (len <= 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }
        return Math.max(nums[0] + find(nums, 2), nums[1] + find(nums, 3));
    }

    public int find(int[] nums, int index) {
        int len = nums.length;
        if (index >= len) {
            return 0;
        }
        if (index == len - 1) {
            return nums[len - 1];
        }
        int x;
        int y;
        if (map.containsKey(index + 2)) {
            x = map.get(index + 2);
        } else {
            x = find(nums, index + 2);
            map.put(index + 2, x);
        }
        if (map.containsKey(index + 3)) {
            y = map.get(index + 3);
        } else {
            y = find(nums, index + 3);
            map.put(index + 3, y);
        }
        return Math.max(nums[index] + x, nums[index + 1] + y);
    }
}
```
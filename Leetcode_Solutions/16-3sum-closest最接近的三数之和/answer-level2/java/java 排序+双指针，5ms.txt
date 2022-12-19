### 解题思路
通过排序完成后，不断跳过重复元素进行求最小差 找到最接近的值

### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        // 先排序
        Arrays.sort(nums);
        int i = 0;
        // 最小差
        int diff = Integer.MAX_VALUE;
        // 结果
        int res = 0;
        while (i < nums.length - 2) {
            int head = i + 1;
            int tail = nums.length - 1;
            while (head < tail) {
                int sum = nums[i] + nums[head] + nums[tail];
                if (sum == target) {
                    // 如果等于target 直接返回
                    return target;
                }
                // 更新最小差
                int d = target - sum;
                if (Math.abs(d) < diff) {
                    diff = Math.abs(d);
                    res = sum;
                }
                // 加速跳过重复 head or tail
                if (sum > target) {
                    while (head < tail && nums[tail] == nums[tail - 1]) {
                        tail--;
                    }
                    tail--;
                } else {
                    while (head < tail && nums[head] == nums[head + 1]) {
                        head++;
                    }
                    head++;
                }
            }
            // 加速跳过重复 i
            while (i<nums.length-2 && nums[i] == nums[i + 1]) {
                i++;
            }
            i++;
        }
        return res;
    }
}
```
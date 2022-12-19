**题意分析：**
(1) 三数之和最接近目标值，就表示三数之后减去目标值的绝对值最小。
(2) 将一个数组排序以后，三数之和的大小边界就是开始的三个数之和和结尾的三个数之和。
*** 本题需要注意的就是要避免重复遍历和无效遍历的运算。

**方法一：双指针**
```
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        // 初始化 ans 为边界值，表示离 target 最远的和。
        int ans = Integer.MIN_VALUE;
        int len = nums.length;
        if (len < 3) {
            throw new IllegalArgumentException("数组元素不够三个！");
        }
        // 对数组排序，方便双指针移动。
        Arrays.sort(nums);
        // 判断 target 如果在数组和的边界之外则直接返回边界值。
        if (target <= nums[0] + nums[1] + nums[2]) {
            return nums[0] + nums[1] + nums[2];
        } else if (target >= nums[len - 1] + nums[len - 2] + nums[len - 3]){
            return nums[len - 1] + nums[len - 2] + nums[len - 3];
        }
        // 循环固定第一个数，根据双指针从它之后去选择另外两个数。
        for (int i = 0; i < len - 2; i++) {
            // 相同的第一个数只固定一次，避免重复运算。
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int L = i + 1, R = len - 1;
            while (L < R) {
                // 判断当前循环能得到的最小三数和。
                int min = nums[i] + nums[L] + nums[L + 1];
                if (target < min) {
                    if (Math.abs(ans - target) > Math.abs(min - target)) {
                        ans = min;
                    }
                    break;
                }
                // 判断当前循环能得到的最大三数和。
                int max = nums[i] + nums[R] + nums[R - 1];
                if (target > max) {
                    if (Math.abs(ans - target) > Math.abs(max - target)) {
                        ans = max;
                    }
                    break;
                }
                int sum = nums[i] + nums[L] + nums[R];
                // 如果三数之和等于 target 则直接返回。
                if (sum == target) {
                    return sum;
                }
                // 根据差的绝对值判断离 target 最近的和。
                if (Math.abs(target - sum) < Math.abs(target - ans)) {
                    ans = sum;
                }
                // 根据三数之和与 target 大小的比较来移动俩指针。
                if (sum > target) {
                    R--;
                    while (L < R && nums[R + 1] == nums[R]) {
                        R--;
                    }
                } else {
                    L++;
                    while (L < R && nums[L - 1] == nums[L]) {
                        L++;
                    }
                }
            }
        }
        return ans;
    }
}
```

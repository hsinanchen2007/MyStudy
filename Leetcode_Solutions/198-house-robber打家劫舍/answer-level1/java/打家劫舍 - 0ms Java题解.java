```Java
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        } else if (nums.length == 1) {
            return nums[0];
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length - 2; i++) {
            max = Math.max(nums[i], max);
            nums[i + 2] += max;
        }
        return Math.max(nums[nums.length - 1], nums[nums.length - 2]);
    }
}
```
没有多余的变量。

首先特殊处理数组长度为0、1的情况。

## 动态规划
1. 状态定义：

    `F(N)`表示打家劫舍到第N间房子的最大收益（N=0是起点）。
1. 状态转移方程定义（其中nums数组是题设中给出的，每间房子的收益）：
    ```
    F(0)=nums[0]
    F(1)=nums[1]
    F(N)=max(F(0), F(1), ..., F(N-3), F(N-2)) + nums[N], N>=2
    ```

## 转化成代码
上面的动态规划状态转移方程可以写出倒序遍历数组的代码，不过这样需要递归，时间复杂度比较高。

正序遍历的好处是，每算出一个`F(N)`就可以放到nums数组里，不需要递归。

不过要注意正序遍历的索引`i∈[0, nums.length-3]`，`i+2∈[2, nums.length-1]`，所以实际上`i+2`才是状态转移方程中的`N`。

用`max`来表示`max(F(0), F(1), ..., F(N-3), F(N-2))`。
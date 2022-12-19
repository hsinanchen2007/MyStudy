## 思路

这其实说白了就是子串的题目，所以必须使用动态规划去做。做 dp 的题目，我觉得首先最重要的不是状态转移方程，而是 dp 数组的含义是什么，只有这个确定对了，状态方程才能很好的列出来！！！

这里的 dp 数组指的是以第 i 个数 结尾的 连续子序列，由于存在负数，所以必须维护两个 dp 数组，其实这里根本用不到数组，但是为了更加清晰的看到 dp 的思想，我还是用数组来表达吧。

* 我们先考虑都是正数的情况。dp_max[i] 的含义我们已经讲过了，``dp_max[i] = Math.max(nums[i-1],dp_max[i-1]*nums[i-1])``，即 dp_max[i] 这个值只会在这两者产生，要么 乘上之前的会更大，要么 舍弃前面的。
* 接下来考虑负数的情况，所以我们有必要维护一个 dp_min，思路是一模一样的，当遍历的元素为负数时，我们只需要把 dp_max[i-1]，dp_min[i-1]交换即可。
* 最后，只要找到所有dp_max中的数值最大的那个，就是我们需要的值了。



## 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        int[] dp_max = new int[nums.length+1];
        int[] dp_min = new int[nums.length+1];
        if(nums.length == 0) return 0;
        int max = Integer.MIN_VALUE;
        // 由于存在负数，所以需要维护两个数组
        // dp_max[i] 指的是以第 i 个数结尾的 乘积最大 的连续子序列
        // dp_min[i] 指的是以第 i 个数结尾的 乘积最小 的连续子序列
        dp_max[0] = 1;
        dp_min[0] = 1;
        for (int i = 1;i <= nums.length;i++){
            // 如果数组的数是负数，那么会导致 max 变成 min，min 变成 max
            // 故需要交换dp 
            if(nums[i-1] < 0){
                int temp = dp_min[i-1];
                dp_min[i-1] = dp_max[i-1];
                dp_max[i-1] = temp;
            }
            dp_min[i] = Math.min(nums[i-1],dp_min[i-1]*nums[i-1]);
            dp_max[i] = Math.max(nums[i-1],dp_max[i-1]*nums[i-1]);
            max = Math.max(max,dp_max[i]);
        }
        return max;
    }
}
```
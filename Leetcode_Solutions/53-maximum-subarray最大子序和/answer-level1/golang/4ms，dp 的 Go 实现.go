![image.png](https://pic.leetcode-cn.com/d021a6750fa1976927fa04cf8c75b42103350199cb8696a63b0943687b14e6cb-image.png)

经典的最大连续子序列和问题，可用 dp 思想解决

代码：
```
func maxSubArray(nums []int) int {
    curMaxSum := 0          // 当前最大连续子序列和
    allMaxSum := nums[0]    // 全局最大连续子序列和
    for _,x := range nums {
        if curMaxSum < 0 { // 当前最大和如果小于0，直接用当前元素值覆盖这个负值
            curMaxSum = x
        } else {        // 如果当前最大和>=0，继续累加
            curMaxSum += x
        }
        if curMaxSum > allMaxSum {
            allMaxSum = curMaxSum
        }
    }
    return allMaxSum
}
```
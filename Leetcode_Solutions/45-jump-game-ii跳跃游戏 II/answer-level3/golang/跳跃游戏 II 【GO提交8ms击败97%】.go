## 结果

![image.png](https://pic.leetcode-cn.com/1d5460f7d32f3b79040fd0e516dfed02141f00ffeadb2888c9743db80c6acda0-image.png)


## 思路

贪心
1. 定义end为当前步数内能走到的组员边界
2. 定义max为遍历时包括下一步能走到最远的位置
3. 如果走到当前步数的边界end，就更新end为max，同时增加步数
4. 注意当end恰好为n-1的时候会增加步数，但实际已经到达，所以增加步数的判断条件为`i == end && end < n - 1`

## Code

```
func jump(nums []int) int {
    n := len(nums)
    // 步数
    step := 0
    // 包括下一步走到最远的位置
    max := 0
    // 当前步数能走到的边界
    end := 0
    for i:=0;i < n;i++ {
        if i + nums[i] > max {
            max = nums[i] + i 
        }
        // 走到当前步数最远边界
        // 如果end恰好为n-1的话步数就会多计1
        if i == end && end < n - 1 {
            step++
            end = max
        }
    }

    return step
}
```


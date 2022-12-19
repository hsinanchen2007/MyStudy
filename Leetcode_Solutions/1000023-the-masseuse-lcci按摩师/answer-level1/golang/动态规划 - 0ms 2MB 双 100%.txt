### 解题思路
当前预约时间总和 = max(前天预约时间总和加上当前预约的时间, 昨天预约时间总和)

### 代码

```golang
func massage(nums []int) int {
    // dp[i] = max(dp[i-1] + nums[i], dp[i])
    // tody = max(yesterday + nums[i], today)
    // 当前预约时间总和 = max(前天预约时间总和加上当前预约的时间, 昨天预约时间总和)
    today, yesterday := 0, 0
    for _, num := range nums{
        // 实现max函数
        if t:= yesterday + num; t > today{
            today, yesterday = t, today
        } else{
            today, yesterday = today, today
        }
    }
    return today
}
```

### 运行结果
![image.png](https://pic.leetcode-cn.com/aaee7800ac6ed8ce0aa40f17bf6809a1c6b5358c3ebb7ffdb5d0689746e04b55-image.png)

## 解题思路
### 一、暴力法（超出内存）
 - 将每天的价格与后边所有的价格进行运算，得出结果，存储在数组中，最后比较大小即可。
### 二、改进暴力（可运行 324ms、4.3MB）
 - 将每天的价格仅与后边最高的价格进行运算，得出结果，，存储在数组中，最后比较大小即可。

- 代码

```golang
func maxProfit(prices []int) int {
    res := make([]int, 0)
    n := len(prices)
    if n == 0  || n == 1{
        return 0 
    }
    for i := 0; i < n-1; i++{
        res = append(res, prices[i+1+getMax(prices[i+1:])]-prices[i])
    }
    max := res[getMax(res)]
    if max < 0{
        return 0
    }
    return max
}

func getMax(nums []int) int {
    left := 0
    right := len(nums) - 1
    for left < right {
        if nums[left] < nums[right]{
            left++
        } else {
            right--
        }
    }
    return left
}
```

### 三、动态规划
```golang
func maxProfit(prices []int) int {
    dp_0 := 0
    dp_1 := 0x7fffffff
    for i := 0; i < len(prices); i++{
        dp_0 = max(dp_0, prices[i]-dp_1)
        dp_1 = min(dp_1, prices[i])
    }
    return dp_0
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min (a, b int) int {
    if a < b {
        return a
    }
    return b
}
```
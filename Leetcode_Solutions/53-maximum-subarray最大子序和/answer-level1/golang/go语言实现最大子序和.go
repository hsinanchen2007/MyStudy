### 解题思路
![image.png](https://pic.leetcode-cn.com/31164503d034c3b01f94d00089f56015461884a71a8b513a7caabdc5405d491c-image.png)

### 代码

```golang
func maxSubArray(nums []int) int {
    if len(nums) < 1 {
        return 0
    }

    dp := nums[0]
    max := dp

    for i := 1;i < len(nums);i++ {
        if dp > 0 {
            dp = dp +nums[i]
        }else{
            dp = nums[i]
        }
        if dp > max {
            max = dp
        }
    }
    return max
    
}
```
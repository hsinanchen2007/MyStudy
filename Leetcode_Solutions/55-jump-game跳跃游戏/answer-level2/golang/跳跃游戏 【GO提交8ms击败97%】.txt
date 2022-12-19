## 结果

![image.png](https://pic.leetcode-cn.com/cb26fd6421cde580f1f4fe000a6f6d458e10c99367a2b3c52cc7122643ab7f5e-image.png)

## 思路

实际上是贪心的思路

1. 定义一个变量have记录自己当前能走多远，然后开始走
2. 如果走到位置`nums[i]`且`nums[i]>have`，就更新当前能走最远的步数
3. 继续走，直到`have==0`或走到末尾为止。

## Code

```
func canJump(nums []int) bool {
    n := len(nums)
    have := nums[0]
    idx := 0
    for idx < n - 1 && have > 0 {
        idx++
        have--
        if nums[idx] > have {
            have = nums[idx]
        }
    }
    return idx == n - 1
}
```


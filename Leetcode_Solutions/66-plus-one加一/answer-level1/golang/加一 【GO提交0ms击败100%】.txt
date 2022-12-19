## 结果

![image.png](https://pic.leetcode-cn.com/e507b14e1ce264d2552d5c8a548119d484e6717956de29ba5d45c26a704ece26-image.png)

## 思路

- 设置一个carry保存是否进位，根据提议，开始时carry设为1
- 整数相加进位的思路，从最后一位开始先前遍历，判断是否产生进位
- 这里要注意的是遍历结束后可能会有进位的情况，这个时候需要在数组前端补1

## Code

```
func plusOne(digits []int) []int {
    carry := 1
    n := len(digits)
    for i:=n-1;i>-1;i-- {
        digits[i] += carry
        carry = digits[i]/10
        digits[i] %= 10
    }
    if carry > 0 {
        digits = append([]int{carry}, digits...)
    }
    return digits
}
```


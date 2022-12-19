### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/3d06d25d40fea2646bb3f474c0b64a42fb1dbbe890d4c30f066a9e94e77a0ea1-%E6%8D%95%E8%8E%B7.PNG)




### 代码

```golang
func plusOne(digits []int) []int {
    l := len(digits) - 1
    for i := l; i >= 0; i-- {
        if digits[i] != 9 {
            digits[i]++
            return digits
        }else {
            digits[i] = 0
        }
    }
    if digits[0] == 0 {
        digits[0] = 1
        digits = append(digits,0)
    }
    return digits
}
```
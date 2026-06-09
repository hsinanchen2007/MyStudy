
![image.png](https://pic.leetcode-cn.com/68e02ff1a576dd91e038992f0de9bff62012adc5abb788b78321da593472103a-image.png)

模拟加法运算，注意超过数位的情况要手动加一位，比如输入 [9 9]，输出应为 [1 0 0]，记得拼接数组。

Go 语言中优雅的合并切片（拼接数组）的方式为：
```
append(a, b...)  // 合并切片 a 和 b，b... 意思为将切片 b 转换为参数列表
```

代码：
```
func plusOne(digits []int) []int {
    for i:=len(digits)-1; i>=0; i-- {
        if digits[i] < 9 {  // 当前位置不用进位，+1，然后直接返回
            digits[i]++
            return digits
        } else {            // 要进位，当前位置置0
            digits[i] = 0
        }
    }
    return append([]int{1}, digits...)
}
```
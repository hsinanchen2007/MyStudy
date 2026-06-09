### 结果

![image.png](https://pic.leetcode-cn.com/39f64c816bb006cc762f97f31b41a6e113ac15e3ee0b54bcfd485e1260b38e13-image.png)


### 解题思路

分三种情况处理：正数，0，负数
- 对于0，显然为”0“
- 对于负数，标记后转化为正数操作，最后再转回来
- 对于正数，采用从右向左计算位的方式，先用num%7获取个位数，再把num减去个位数后右一一位（num/=7），循环直到num为0即可

### 代码

```golang
func convertToBase7(num int) string {
    var result []rune
    if num == 0 {
        return "0"
    }
    
    var ne = num < 0
    if ne {
        num = -num
    }
    for num > 0 {
        n := num % 7
        result = append([]rune{rune(n+'0')}, result...)
        num -= n
        num /= 7
    }
    if ne {
        result = append([]rune{rune('-')}, result...)
    }
    return string(result)
}
```
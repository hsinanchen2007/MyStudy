## 结果

![image.png](https://pic.leetcode-cn.com/3b474252f613ef0c03ec2f5ca9cc2ad97f4db3e697a0845329e57019b85d539e-image.png)

## 思路

去掉尾部空格（如果有），之后从尾部开始找，同时计算长度，直到遍历到开头或者遍历到空格为止

## Code

```
func lengthOfLastWord(s string) int {
    // 去掉尾部空格
    for s!= "" && s[len(s)-1] == ' ' {
        s = s[:len(s)-1]
    }
    n := len(s)
    sum := 0
    // 从尾部开始找
    for i:=n-1;i>=0 && s[i] != ' ';{
        i--
        sum++
    }
    return sum
}
```


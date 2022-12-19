### 解题思路
此处撰写解题思路

### 代码

```golang
func numberOfSteps (num int) int {
    if num == 0 {
        return 0
    }
    res := 0
    for num > 0 {
        if num % 2 == 0{
            num = num / 2
        } else {
            num = num - 1
        }
        res++
    }
    return res
}
```
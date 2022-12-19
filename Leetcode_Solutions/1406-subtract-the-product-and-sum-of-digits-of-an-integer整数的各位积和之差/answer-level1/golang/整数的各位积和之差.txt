### 解题思路
引入了一个go语言字符串转换包strconv
strconv.Itoa(int) 将数字转为字符串
strconv.Atoi(string) 将字符串转为数字
上述方法均有两个返回值,第二个返回值为错误信息,我们这里不需要,因此使用一个只写变量`_`
此题可用数学解法,但计算给定数字的位数比较麻烦,因而转成字符串处理比较方便
### 代码

```golang
func subtractProductAndSum(n int) int {
    str_n := strconv.Itoa(n)
    product := 1
    sum := 0
    for i :=0 ; i < len(str_n); i++{
        flag := i+1
        digit, _ := strconv.Atoi(str_n[i:flag])
        product *= digit
        flag++
    }
    for i :=0 ; i < len(str_n); i++{
        flag := i+1
        digit, _ := strconv.Atoi(str_n[i:flag])
        sum += digit
        flag++
    }
    return product - sum
}
```
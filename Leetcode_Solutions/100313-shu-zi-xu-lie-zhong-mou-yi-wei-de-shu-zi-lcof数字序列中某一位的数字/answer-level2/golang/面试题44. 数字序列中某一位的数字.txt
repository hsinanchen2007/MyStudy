### 题目
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

 

### 解题思路
1. 设一个数 dight 表示第n位对应的这个数是几位数
2. 按照n-1*9-2*90-3*900.....这个思路直到n不能再减
3. 以n / dight 得出这个数是第几个
4. 然后计算n%dight 是这个数的第几位
5. 

## 代码

```golang
func findNthDigit(n int) int {

	dight := 1.0
    for n -  int(dight*(math.Pow(10, dight)-math.Pow(10, dight-1.0))) >= 0 {
        n = n -  int(dight*(math.Pow(10, dight)-math.Pow(10, dight-1.0)))
        dight++
    }
    fmt.Println(dight, n)

    num := int(math.Pow(10, dight-1)) + n / int(dight)
    mod := n % int(dight)
    if mod == 0 {
        return (num-1) % 10
    } else {
        return (num/int(math.Pow(10, dight-float64(mod))))%10
    }

}
```
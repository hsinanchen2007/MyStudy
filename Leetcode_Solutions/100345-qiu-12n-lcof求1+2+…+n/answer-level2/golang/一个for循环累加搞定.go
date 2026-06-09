### 解题思路

题目不让乘除法，那就用一个`for`循环累加即可搞定。  

### 代码

```golang
func sumNums(n int) int {
    sum := 0
    for i:=0;i<=n;i++ {
        sum += i
    }
    return sum
}
```
### 解题思路
先计算出最大值

### 代码

```golang
func printNumbers(n int) []int {
  var res []int
  maxNum:=9
  for i:=1; i<n;i++{
    maxNum *= 10
    maxNum += 9
  }
  for i:=1;i<=maxNum;i++{
    res = append(res, i)
  }
  return res
}
```
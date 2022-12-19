### 解题思路
* 简单的取余累加，不过难点在于边界的考虑

### 代码

```golang
func reverse(x int) int {
  const INTMAX uint = 1<<31-1
  sign := false
  if x<0{
    x=-x
    sign=true
  }
  res := uint(0)
  for x!=0{
    res = 10 *res + uint(x%10)
    //fmt.Println(res,INTMAX,res>INTMAX)
    if (!sign && res > INTMAX) || (sign && res > INTMAX+1){
      return 0
    }
    x = x / 10
  }
  if sign{
    return -int(res)
  }
  return int(res)
}
```
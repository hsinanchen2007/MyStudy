### 解题思路
记录下大神的题解，看不懂，先记下来
### 代码

```golang
func stoneGameIII(stoneValue []int) string {
  n := len(stoneValue)
  ts := 0
  f:=make([]int, 50010)
  f[n],f[n+1],f[n+2] = 0, 0, 0
  for i:=n-1;i>=0;i--{
    ts += stoneValue[i]
    mi := f[i+1]
    for j:=2;j<=3;j++{
      mi = min(mi, f[i+j])
    }
    f[i] = ts-mi
  }
  if f[0]+f[0] > ts {
    return "Alice"
  } else if (f[0] +f[0] == ts) {
    return "Tie"
  } else {
    return "Bob"
  }
}
func min(a, b int)int{
  if a < b {
    return a
  }
  return b
}
```
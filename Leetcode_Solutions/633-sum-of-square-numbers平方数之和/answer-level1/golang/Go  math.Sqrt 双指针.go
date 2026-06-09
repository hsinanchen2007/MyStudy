### 解题思路
Go  math.Sqrt 解法 是件复杂度 O(sqrt(c)) , 空间复杂度O(1)

### 代码

```golang
func judgeSquareSum(c int) bool {
    if c < 0 {
        return false
    }
    i,j := 0, int(math.Sqrt(float64(c)))
    for i <= j {           // <=
        sum:= i*i + j*j
        if sum == c {
            return true
        } else if sum > c {
            j--
        } else {
            i++
        }
    }
    return false
}
```
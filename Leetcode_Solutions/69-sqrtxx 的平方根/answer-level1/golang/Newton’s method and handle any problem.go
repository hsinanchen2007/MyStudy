### 解题思路
Newton's method and handle any problem

### 代码

```golang
func mySqrt(x int) int {
    if x < 2 {
      return x  
    }
    y := x / 2
    for y * y > x {
        y = ( y + x / y ) / 2 //Newton's method
    }
    return int( y )
}
```
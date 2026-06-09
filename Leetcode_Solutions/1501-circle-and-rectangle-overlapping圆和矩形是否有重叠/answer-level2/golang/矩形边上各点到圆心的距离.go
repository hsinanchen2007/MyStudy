### 解题思路
- 判断边上各点到圆心距离即可
- 书写方便，可以遍历所有整数点

### 代码

```golang
func checkOverlap(radius int, x_center int, y_center int, x1 int, y1 int, x2 int, y2 int) bool {
    for i := x1; i <= x2; i++{
        for j := y1; j <= y2; j++{
            if (i-x_center)*(i-x_center) + (j-y_center)*(j-y_center) <= radius*radius{
                return true
            }
        }
    }
    return false
}
```
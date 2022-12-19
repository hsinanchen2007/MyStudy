### 解题思路
此处撰写解题思路
### 代码

```golang
func maxArea(height []int) int {
    a := 0
    s := 0
    for i, _ := range height{
        for j := i+1 ; j < len(height) ; j++{
            if height[j] >= height[i]{
                s = (j-i) * height[i]
            } else {
                s = (j-i) * height[j]
            }
            if s > a{
                a = s
            }
        }
    }
    return a
}
```
### 解题思路


### 代码

```golang
func maxArea(height []int) int {
    var low = 0
    var high = len(height)-1
    var o,s int
    for low < high{
        s = (high-low)*min(height[low],height[high])
        if s > o{
            o = s
        }
        if height[low] > height[high]{
            high --
        }else{
            low ++
        }
    }
    return o
}


func min(x,y int) int {
    if x > y{
        return y
    } 
    return x
}
```
 
### 代码

- 暴力法
```golang

// var res=0
// for i:= 0; i < len(height)-1; i++ {
//     for j:=i+1;j<len(height); j++ {
//         var min = height[j]
//         if height[i] < min {
//             min = height[i]
//         }
//         var tmp = min-height[j]
//         if tmp > res {
//             res=tmp
//         }
//     }
// }
```


- 动态规划



```golang
func maxArea(height []int) int {
    var result int
    var pos_left,pos_right = 0, len(height) - 1
    for (pos_left<pos_right && pos_left <len(height) && pos_right > 0){
        var cur int
        if height[pos_left] < height[pos_right] {
            cur = height[pos_left] * (pos_right - pos_left)
            pos_left ++
        } else {
            cur = height[pos_right] * (pos_right - pos_left)
            pos_right --
        }
        if cur > result {
            result = cur
        }
    }

    return result
}
```
- **执行结果：**
![0.png](https://pic.leetcode-cn.com/83eaa1c01c33c89e42780c4d18934b3e20f195e8c072d3df8fdae65e8057d4f7-0.png)

- **时间复杂度：O(n)**
- **空间复杂度：O(1)**

- **思路**
1. 先遍历一遍找到最大值的位置maxIndex
2. 以maxIndex一分为二，处理方式相同(左边正序，右边倒序处理)
3. 从左向右扫描，有值的位置作为起始位置，低于起始位置的填坑（计数），遇到大于等于起始位置的就重新作为起始位置

- **代码**
```
func trap(height []int) int {
    lens := len(height)
    if lens <= 1 {
        return 0
    }
    //先遍历一遍找到最大值的位置maxIndex
    var maxIndex,maxHeight int
    for i:=0; i<lens; i++ {
        if height[i] > maxHeight {
            maxHeight = height[i]
            maxIndex = i
        }
    }
    //计算左侧
    var res,begin int
    for i:=0; i<=maxIndex; i++ {
        if height[i] < begin {
            res += begin - height[i]
        }
        if height[i] > 0 && height[i] >= begin {
            begin = height[i]
        }
    }
    //计算右侧
    begin = height[lens-1]
    for i:=lens-1; i>=maxIndex; i-- {
        if height[i] < begin {
            res += begin - height[i]
        }
        if height[i] > 0 && height[i] >= begin {
            begin = height[i]
        }
    }
    return res
}
```

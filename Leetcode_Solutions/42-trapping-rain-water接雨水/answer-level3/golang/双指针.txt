### 解题思路
另一个用栈实现的看了好几遍，还是没理清，感觉双指针理解起来容易很多

### 代码

```golang
func trap(height []int) int {
    var left, right, leftMax, rightMax, water int 
    right = len(height)-1
    for left < right{
        if height[left] < height[right]{
            if height[left] >= leftMax{  //此时肯定是左低右高，leftMax 其实就是上一次循环的柱子高度，如果这次的柱子更高，肯定不能蓄水，指针指向当前的柱子
                leftMax = height[left]
            }else{
                water += leftMax - height[left]//把差值加上就是蓄水量
            }
            left++
        }else{
            if height[right] >= rightMax{    //此时左指针已经移动到了中间的某个位置，使得 height[left] > height[right]，所以移动右指针
                rightMax = height[right]
            } else{
                water += rightMax - height[right]
            }
            right--
        }
    }
    return water
}
```
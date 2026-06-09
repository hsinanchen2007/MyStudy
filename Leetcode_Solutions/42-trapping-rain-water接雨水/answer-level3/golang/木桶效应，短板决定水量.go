### 解题思路
#### 动态求边界
* 思路
  * 明确一点，第i块能接雨水的量是由它两边最大高度的最小值和当前高度决定的，即$min(leftMax,rightMax)-height[i]$
  * 该思路就是将所有块的左边最大和右边最大求出来，然后求解每块可以接的水量
* 性能
  * 时间复杂度 $O(N)$, 击败 20% 用户。
  * 空间复杂度 $O(N)$, 击败 50% 用户。
#### 双指针
* 思路
  * 在动态求边界的过程中发现左边最大值是从左往右递增的，而右边的最大值是从右往左递增的。而且因为能接的雨水是由左右两边
的短板决定的，所以用两个指针从两边向中间聚拢的过程中，左右两边的最大值随小谁向中间移动，而且之前位置的接水量就可以直接算出。
* 性能
  * 时间复杂度 $O(N)$, 击败 80% 用户。
  * 空间复杂度 $O(1)$, 击败 100% 用户。

### 代码

```golang


func trap(height []int) int {
  hLen := len(height)
  if hLen < 3{return 0}
  left,right:=1,hLen-2
  leftMax,rightMax := 0,0
  res := 0
  for left<=right{
    if height[left-1]> leftMax{leftMax = height[left-1]}
    if height[right+1] > rightMax{rightMax = height[right+1]}
    if leftMax > rightMax{
      if rightMax > height[right]{
        res += rightMax - height[right]
      }
      right--
    }else{
      if leftMax > height[left]{
        res += leftMax - height[left]
      }
      left++
    }
  }
  return res
}

/*
func trap(height []int) int {
  hLen := len(height)
  if  hLen == 0{return 0}
  leftMax,rightMax := make([]int,hLen),make([]int,hLen)
  leftMax[0] = 0
  for i:=1;i<hLen;i++{
    if height[i-1] > leftMax[i-1]{
      leftMax[i] = height[i-1]
    }else{
      leftMax[i] = leftMax[i-1]
    }
  }
  fmt.Println(leftMax)
  rightMax[hLen-1] = 0
  for i:=hLen-2;i>=0;i--{
    if height[i+1] > rightMax[i+1]{
      rightMax[i] = height[i+1]
    }else{
      rightMax[i] = rightMax[i+1]
    }
  }
  fmt.Println(rightMax)
  res := 0
  for i,v := range height{
    max := leftMax[i]
    if leftMax[i] > rightMax[i]{
      max = rightMax[i]
    }
    if max > v{
      res += max -v 
    }
  }
  return res 

}
*/
```
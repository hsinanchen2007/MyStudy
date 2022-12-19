### 解题思路
此处撰写解题思路

### 代码

```golang
func massage(nums []int) int {
    dpMax := []int{}
    if len(nums) == 0{
        return 0
    }else if len(nums) == 1{
        return nums[0]
    }

    dpMax = append(dpMax,[]int{0,0}...)
    for i:= range nums{
        maxT := max(dpMax[i]+nums[i],dpMax[i+1])
        dpMax = append(dpMax,maxT)
    }
    return dpMax[len(dpMax)-1]
}

func max(a,b int)int{
    if a>b {
        return a
    }
    return b
}
```
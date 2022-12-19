### 解题思路
使用了更优雅的for range

### 代码

```golang
func twoSum(nums []int, target int) []int {
    
    numMap := make(map[int]int)
    for i:=0; i < len(nums); i++ {
       v := nums[i]
       diff := target-v

       if val, ok := numMap[diff]; ok {
          return []int{val, i} 
       }
       numMap[v] = i
    }
    return []int{-1, -1}
}
```
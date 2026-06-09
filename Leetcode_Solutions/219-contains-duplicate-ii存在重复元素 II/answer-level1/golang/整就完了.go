### 解题思路
此处撰写解题思路

### 代码

```golang
func containsNearbyDuplicate(nums []int, k int) bool {

    strMap := make(map[string]int)

    for i :=0 ; i < len(nums); i++ {
        strMap[strconv.Itoa(nums[i])]++

        if strMap[strconv.Itoa(nums[i])] >= 2 {
            for j := 0; j < i; j++ {
                if nums[j] == nums[i] {
                    if i - j <= k {
                        return true
                    }
                }
            }

        }
        
    }
    return false
}
```
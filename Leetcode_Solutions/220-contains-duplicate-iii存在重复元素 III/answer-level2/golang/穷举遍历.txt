```
func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
    // 考虑k >= len(nums) 的情况存在，因为题目中并未说明k t 和切片元素数量的大小关系
    for i := 0; i < len(nums); i++ {
        for j := 1; j <= k; j++ {
            if i+j >= len(nums) {
                break
            }
            tmp := nums[i+j] - nums[i]
            if abs(tmp) <= t {
                return true
            }
        }
    }
    return false
}

func abs(data int) int {
    if data < 0 {
        return -1*data
    }

    return data
}

```
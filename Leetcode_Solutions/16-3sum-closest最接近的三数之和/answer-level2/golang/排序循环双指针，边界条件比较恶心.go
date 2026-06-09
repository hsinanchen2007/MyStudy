### 解题思路
排序循环双指针
### 代码

```golang
func threeSumClosest(nums []int, target int) int {
    // 排序，双指针
    l := len(nums)
    if l < 3 {
        return 0
    }

    sort.Ints(nums)
    // 不用计算绝对值，记录差距
    dist := math.MaxInt64
    // 记录结果
	res := math.MaxInt64
    for i := 0; i < l - 2; i++ {
        if i > 0 && nums[i] == nums[i - 1] {
            // 剪枝重复的不计算
            continue
        }
        j := i + 1
        k := l - 1
        for j < k {
            if j > i + 1 && nums[j] == nums[j - 1] {
                j++
                continue
            }
            // 三数之和
            sum := nums[i] + nums[j] + nums[k]
            // 正好匹配
            if sum == target {
                return sum
            } else if sum > target {
                if dist > sum - target {
                    dist = sum - target
                    res = sum
                }
 
                for k < l - 1 && k > j && nums[k] == nums[k + 1] {
                    k--
                    // 剪枝重复的不计算
                    continue
                }
                k--
            } else {
                if dist > target - sum {
                    dist = target - sum 
                    res = sum
                }
                j++
            }
        }
    }
    return res
}
```
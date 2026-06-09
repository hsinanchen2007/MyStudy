### 解题思路
用个flag，将flag初始值设为-1，如果没找到就是-1，找到了记下找到的位置，向两边扩散遍历

### 代码

```golang
func search(nums []int, target int) int {
    if len(nums) == 0 {
        return 0
    }
    l, r := 0, len(nums) - 1
    flag := -1
    for l <= r {
        mid := (r - l) / 2 + l
        if nums[mid] == target {
            flag = mid
            break
        } else if nums[mid] > target {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    if flag < 0 {
        return 0
    }
    cnt := 1
    for i := flag+1; i < len(nums) && nums[i] == target; i++ {
        cnt++
    }
    for i := flag-1; i >= 0 && nums[i] == target; i-- {
        cnt++
    }
    return cnt
}
```
### 解题思路
此处撰写解题思路

### 代码

```golang
func threeSumClosest(nums []int, target int) int {
     n := len(nums)
     if n < 3 {
         return target
     }
    // 对数组进行排序
    Sort(nums)
    total := nums[0] + nums[1] + nums[2] 
    for i := 0; i < n; i++ {
        L := i + 1
        R := n - 1
        for L < R {
            sum := nums[i] + nums[L] + nums[R]
            if math.Abs(float64((target - total))) > math.Abs(float64((target - sum))) {
                total = sum
            }
            if sum == target {
                return target
            } else if sum > target {
                R--
            } else {
                L++
            }
        }
    } 
    return total
}

func Sort(nums []int) {
    sort(nums, 0, len(nums) - 1)
}

func sort(arr []int, start int, end int) {
    if start >= end {
        return
    }
    i := cut(arr, start, end)
    sort(arr, start, i - 1)
    sort(arr, i + 1, end)
}

func cut(arr []int, start int, end int) int {
    pivot := arr[end]
    p := start
    q := start
    for ; q < end; q++ {
        if arr[q] < pivot {
            arr[p], arr[q] = arr[q], arr[p]
            p++
        }
    }

    arr[p], arr[end] = arr[end], arr[p]
    return p
}
```
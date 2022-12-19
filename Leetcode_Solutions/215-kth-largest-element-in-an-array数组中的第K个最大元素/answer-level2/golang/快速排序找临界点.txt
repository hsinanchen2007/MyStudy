### 解题思路
快排思想
### 代码

```golang
func findKthLargest(nums []int, k int) int {
    l := len(nums)
    if l == 0 || k == 0 {
        return 0
    }
    if k > l {
        return 0
    }

    _, res := getIndex(nums, k)
    return res
}

func getIndex(nums []int, k int) (int, int) {
    tmp := nums[len(nums) - 1]
    p := 0
    q := len(nums) - 1
    for p < q {
        for p < q && nums[p] <= tmp {
            p++
        }
        nums[q] = nums[p]
        for p < q && nums[q] > tmp {
            q--
        }
        nums[p] = nums[q]
    }
    nums[p] = tmp
    if len(nums) - p == k {
        return p, nums[p]
    }
    if len(nums) - p > k {
        return getIndex(nums[p + 1 :], k)
    }
    return getIndex(nums[:p], k + p - len(nums))
}
```
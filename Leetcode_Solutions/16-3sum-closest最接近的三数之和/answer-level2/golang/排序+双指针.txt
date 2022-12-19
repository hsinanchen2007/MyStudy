先将数组排序，然后进行一次遍历，若遇到与前一个数相同则直接跳过，遍历的过程中使用双指针往中间逼近，寻找最接近的和

```
func threeSumClosest(nums []int, target int) int {
    sort.Ints(nums)
    res := nums[0] + nums[1] + nums[2]
    n := len(nums)
    for i := 0; i < n - 2; i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        l := i + 1
        r := n - 1
        for l < r {
            tmp := nums[i] + nums[l] + nums[r]
            if tmp == target {
                res = target
                return res
            }
            a := math.Abs(float64(tmp-target))
            b := math.Abs(float64(res-target))
            if a < b {
                res = tmp
            }
            if tmp < target {
                l++
            } else {
                r--
            }
        }
    }
    return res
}
```

计数
```
func majorityElement(nums []int) int {
    c := map[int]int{}
    for _, v := range nums {
        c[v]++
    }
    for key ,v := range c {
        if v > len(nums)/2 {
            return key
        }
    }
    return nums[0]
}
```

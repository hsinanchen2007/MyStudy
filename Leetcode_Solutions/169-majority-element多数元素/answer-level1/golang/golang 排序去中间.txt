### 解题思路
1. 多数的定义是超过一半的数,所以排序后中间的数一定是多数

### 代码

```golang
func majorityElement(nums []int) int {
    sort.Ints(nums)
    return nums[len(nums)/2]
    // m := make(map[int]int,0)
    // for _,v := range nums{
    //     m[v]++
    //     if m[v] >= len(nums)/2+1{
    //         return v
    //     }
    // }
    // return -1
}
```
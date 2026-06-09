```
func twoSum(nums []int, target int) []int {
    var numMap = make(map[int]int)
    for i:=0; i<len(nums); i++ {
        t := target - nums[i]
        if v, ok := numMap[t]; ok {
            return []int{v, i}
        }
        numMap[nums[i]] = i
    }
    return []int{}
}
```

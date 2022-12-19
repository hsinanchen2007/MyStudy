```golang
func twoSum(nums []int, target int) []int {
    mapp := make(map[int]int)
    for i:=0; i<len(nums); i++ {
        other := target - nums[i]
        v,ok := mapp[other]
        if ok && v!=i {
            return []int {v,i}
        }
        mapp[nums[i]] = i
    }
    return nil
}
```
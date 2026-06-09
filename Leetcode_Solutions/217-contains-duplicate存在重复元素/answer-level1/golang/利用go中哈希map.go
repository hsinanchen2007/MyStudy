```
func containsDuplicate(nums []int) bool {
    mmap := make(map[int]int)

    for i := 0; i < len(nums); i++ {
        if _, ok := mmap[nums[i]]; ok {
            return true
        } else {
            mmap[nums[i]] = 1
        }
    }
    return false


}

```
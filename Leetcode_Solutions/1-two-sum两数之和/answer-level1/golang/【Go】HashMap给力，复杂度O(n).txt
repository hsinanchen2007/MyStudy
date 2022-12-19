hashMap中的key为数组的值，value为下标，因为我们需要返回的是下标，所以把下标存到hashMap中。
利用hashMap快速查找的特点，将复杂度降到O(n)
func twoSum(nums []int, target int) []int {
      m := make(map[int]int, len(nums))
    
    for i,num := range nums{
        if idx,ok := m[target - num];ok{
            return []int{idx,i}
        }
        m[num] = i
    }
    return []int{}
}

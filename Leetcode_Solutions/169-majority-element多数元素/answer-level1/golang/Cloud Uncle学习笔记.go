1. 哈希
```
func majorityElement(nums []int) int {
    if nums == nil {
        return 0
    }
    
    numExist := make(map[int]int)
    for i:=0; i<len(nums); i++ {
        numExist[nums[i]]++          
    }
    
    k, v := 0, 0
    for num, count := range numExist {
        if count > v {
            k = num
            v = count
        }
    }
    
    return k
}
```
哈希改进
```
func majorityElement(nums []int) int {
    max := nums[0]
    maxMap := map[int]int{max: 0}
    for i:=0; i<len(nums); i++ {
        maxMap[nums[i]]++
        if maxMap[nums[i]] > maxMap[max] {
            max = nums[i]
        }
    }
    return max
}
```
2.排序
```
func majorityElement(nums []int) int {
    sort.Ints(nums)
    return nums[len(nums)/2]
}
```

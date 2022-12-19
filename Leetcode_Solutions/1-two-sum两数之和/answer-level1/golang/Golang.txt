### 解题思路
主要就是利用hashmap,判断所需要的值是否在hash中出现

### 代码

```golang
func twoSum(nums []int, target int) []int {
    if len(nums) == 0 {
		return nil
	}
	hashMap := make(map[int]int)
	aSlice := make([]int,0,len(nums))
	// i本身就是索引
	for i := 0; i < len(nums); i++ {
		if _, ok := hashMap[nums[i]]; !ok {
			hashMap[target-nums[i]] = i
		} else {
			aSlice = append(aSlice, i)
			aSlice = append(aSlice, hashMap[nums[i]])
			return aSlice
		}
	}
	return nil
}
```
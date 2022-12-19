### 借助于map的快速方法，执行耗时 4ms, 击败 98.83% 的go用户
```
func twoSum(nums []int, target int) []int {
	hashMap := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		another, exist := hashMap[target-nums[i]]
		if exist {
			return []int{another, i}
		}
		hashMap[nums[i]] = i
	}
	return []int{}
}
```

### 常规的比较方法，耗时稍长，48ms
```
func twoSum(nums []int, target int) []int {
  length := len(nums)
  var i, j int
  for ; i < length - 1; i++ {
    for j = i + 1; j < length; j++ {
      if nums[i] + nums[j] == target {
        return []int{i, j}
      }
    }
  }
  return []int{}
}
```
结论：时间、空间的置换

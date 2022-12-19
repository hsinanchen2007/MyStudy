### 解题思路一: 哈希表+指针
	遍历数组，判断当前元素是否存在哈希表中，如果不存在哈希表中则，赋值当前指针位置的元素值。如果存在则指针不递增

时间复杂度：O(n)
空间复杂度：O(n)-哈希表

### 代码

```golang

func removeDuplicates(nums []int) int {
	maps := map[int]int{}
	index := 0
	for _,val := range nums{
		_,ok := maps[val]
		if !ok {
			nums[index] = val
			index++
			maps[val] = val
		}
	}
	nums = nums[:index]
	return len(nums)
}
```


### 解题思路:双指针
	index为慢指针，i为快指针，如果nums[index]==nums[i]，则快指针递增。
	如果nums[index]!=nums[i]，将慢指针+1，并将nums[index]赋值为nums[i].
时间复杂度：O(n)
空间复杂度：O(1)

### 代码

```golang

func removeDuplicates(nums []int) int {
	index := 0
	for i:=1; i<len(nums) ;i++  {
		if nums[index]!=nums[i] {
			index++
			nums[index]=nums[i]
		}
	}
	return index +1
}
```
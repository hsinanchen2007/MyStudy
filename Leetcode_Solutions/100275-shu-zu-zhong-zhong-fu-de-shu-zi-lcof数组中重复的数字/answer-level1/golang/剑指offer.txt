### 解题思路
此处撰写解题思路
排序后 如果没有重复, 那么索引和值应该相等,但是有重复所以肯定存在一个使得索引和值不一致,那么只需要判断值和值所在索引的值是否相等
### 代码

```golang
func findRepeatNumber(nums []int) int {
    	//算法思想, 对应的索引和值相等, 然后判断
	for i,j := 0, len(nums); i<j; i++ {
		for i != nums[i]  {
			if nums[i] == nums[nums[i]]{
				return nums[i]
			}else {
				nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
			}
		}
	}
	return -1
}
```
### 解题思路
1.将nums转成val => index的集合 numMap
2.遍历 nums ,并在过程中判断target 与 v 差是否在 numMap中 且 此时的k 不等于 index
3.终止循环并输出结果，这样避免了多层嵌套来遍历，降低了时间复杂度但提升了空间复杂度
### 代码

```golang
func twoSum(nums []int, target int) []int {
   var result [] int
	numMap := make(map[int]int)
	for k, v := range nums {
		numMap[v] = k
	}

	for k,v := range nums{
		index,ok := numMap[target - v]
		if ok == true && k != index {
			return append(result,k,index)
		}
	}
	return result
}
```
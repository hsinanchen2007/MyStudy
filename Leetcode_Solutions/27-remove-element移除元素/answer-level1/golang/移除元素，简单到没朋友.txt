### 解题思路
so easy 
1.声明一个index，用于保留目前数组中替换元素位置
2.遍历所有元素，如果不等于目标元素的值，则替换，index自增1

### 代码

```golang
func removeElement(nums []int, val int) int {
	index := 0
	for i,value := range nums  {
		if nums[i] != val {
			nums[index] = value
			index++
		}
	}
	return index
}
```
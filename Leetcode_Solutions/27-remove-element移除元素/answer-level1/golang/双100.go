### 解题思路
每次循环记录重复元素的个数n，将后面不等于给定值的元素下标前移n位
![image.png](https://pic.leetcode-cn.com/baf05ccab6351bdb002d792400fa4aec022951c080a963edfd7ca08ee8532d88-image.png)
### 代码

```golang
func removeElement(nums []int, val int) int {
    length := len(nums)
	r := 0
	n := 0
	for i := 0; i < length; i++ {
		if nums[i] != val {
			nums[i - n] = nums[i]
			r += 1
		} else {
			n += 1
		}
	}
	return r
}
```
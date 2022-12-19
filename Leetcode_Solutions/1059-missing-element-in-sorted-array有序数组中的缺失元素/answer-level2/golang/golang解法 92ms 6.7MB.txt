### 解题思路
此处撰写解题思路

### 代码

```golang

func missingElement(nums []int, k int) int {
	index := 1
	num := 0
	miss := nums[0] + 1
	for {
		if index == len(nums) {
			diff := k - num
			return miss + diff -1
		}
		v := nums[index]
		if miss != v {
			num += 1
			if num == k {
				return miss
			}
		} else {
			index += 1
		}
		miss += 1
	}

	return miss
}
```
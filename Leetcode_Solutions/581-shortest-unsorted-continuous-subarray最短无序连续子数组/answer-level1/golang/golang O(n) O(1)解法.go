### 解题思路
排序一下然后对比根本就不是这个题的考点

### 代码

```golang
func findUnsortedSubarray(nums []int) int {
	var m,n int
	var min, max int
	min = 1 << 63 - 1
	max = -1 << 63
	//1, 3, 5, 4, 2
	//我们从头开始遍历数组，一旦遇到降序的元素，我们记录最小元素为 minmin 。
	for i:=1; i<len(nums); i++ {
		if nums[i-1] > nums[i] {
			temp := nums[i]
			if temp < min {
				min = temp
				n = n - 1
			}
		}
	}
	//我们逆序扫描数组 numsnums，当数组出现升序的时候，我们记录最大元素为 maxmax。
	for i:=len(nums)-2; i>=0; i-- {
		if nums[i] > nums[i+1] {
			temp := nums[i]
			if temp > max {
				max = temp
				n = n - 1
			}
		}
	}
	if max == -1 <<63 && min == 1 << 63 -1 {
		return 0
	}
	//从头开始找到第一个大于 minmin 的元素
	for k, v := range nums {
		if v > min {
			m = k
			break
		}
	}
	//从尾开始找到第一个小于 maxmax 的元素
	for i:=len(nums)-1; i>=0; i-- {
		if nums[i] < max {
			n = i
			break
		} 
	}

	return n - m + 1
}
```
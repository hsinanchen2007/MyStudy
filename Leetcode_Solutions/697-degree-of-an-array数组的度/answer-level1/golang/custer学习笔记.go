首先按照第一反应写出嵌套循环，但是执行超时

1. 第一步求原数组的度
2. 寻找和原数组的度相同的所有子数组
```go
package degree

import (
	"testing"
)

func findDegree(nums []int) int {
	degree := 0 // 数组的度
	// 原数组的度-数组里任一元素出现频数
	degreeArray := make(map[int]int)
	for _, num := range nums {
		if _, ok := degreeArray[num]; ok {
			degreeArray[num]++
		} else {
			degreeArray[num] = 1
		}
	}
	//fmt.Println(degreeArray)
	// 数组里任一元素出现频数的最大值。
	for _, value := range degreeArray {
		if value > degree {
			degree = value
		}
	}
	//fmt.Println(degree)
	return degree
}
func findShortestSubArray(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	count := len(nums) // 计数
	// 求nums数组的度
	degree := findDegree(nums)

	// 寻找和原数组的度相同的所有子数组
	for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			subArray := nums[i : j+1]
			if findDegree(subArray) == degree {
				if count > len(subArray) {
					count = len(subArray)
				}
			}
		}

	}
	// 返回最短连续子数组的长度

	return count
}

func TestFindShortestSubArray(t *testing.T) {
	num1 := []int{1, 2, 2, 3, 1}
	num2 := []int{1, 2, 2, 3, 1, 4, 2}
	num3 := []int{1}
	num4 := []int{1, 1}

	t.Log(findShortestSubArray(num1)) // 2
	t.Log(findShortestSubArray(num2)) // 6
	t.Log(findShortestSubArray(num3)) // 1
	t.Log(findShortestSubArray(num4)) // 2
}
```

[学习大佬的方法](https://github.com/aQuaYi/LeetCode-in-Go/blob/master/Algorithms/0697.degree-of-an-array/degree-of-an-array.go)

```go
package degree

import (
	"fmt"
	"testing"
)

func findShortestSubArray(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	count := len(nums) // 计数
	degree := 1        // 数组的度
	degreeArray := make(map[int]int) // 数组中每个元素出现的频数
	degreeIndex := make(map[int]int) // 数组中频数第一次出现的下标
	for i, num := range nums {
		degreeArray[num]++
		if degreeArray[num] == 1 {
			degreeIndex[num] = i
		} else {
			l := i - degreeIndex[num] + 1
			if degree < degreeArray[num] || (degree == degreeArray[num] && count > l) {
				degree = degreeArray[num]
				count = l
			}
		}
	}
	if len(degreeArray) == len(nums) {
		return 1
	}

	return count
}

func TestFindShortestSubArray(t *testing.T) {
	num1 := []int{1, 2, 2, 3, 1}
	num2 := []int{1, 2, 2, 3, 1, 4, 2}
	num3 := []int{1}
	num4 := []int{1, 1}
	num6 := []int{2, 1}

	t.Log(findShortestSubArray(num1)) // 2
	t.Log(findShortestSubArray(num2)) // 6
	t.Log(findShortestSubArray(num3)) // 1
	t.Log(findShortestSubArray(num4)) // 2
	t.Log(findShortestSubArray(num6)) // 1
}
```
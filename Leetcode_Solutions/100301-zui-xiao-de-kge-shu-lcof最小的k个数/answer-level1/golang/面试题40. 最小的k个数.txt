### 解题思路
实际上这是一道TOP K 问题
已知的有几种解法
1.全排序,然后取前k个值,此时时间复杂度为O(nlogn)
2.快速排序,然后取前K个数
3.TOP K 解法

### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
	if len(arr) == 0 {
		return arr
	}
	left := 0
	right := len(arr) - 1
	// 1.此处的任务就是去找到基准值
	index := partation(arr, left, right)
	// 如果基准值 不等于K的值
	for index != k-1 {
		// 基准值比 k 大,基准值前面的数组都比K
		if index > k-1 {
			right = index - 1
			index = partation(arr, left, right)
		} else {
			// 基准比K小
			left = index + 1
			index = partation(arr, left, right)
		}
	}
	result := []int{}
	for i := 0; i < k; i++ {
		result = append(result, arr[i])
	}
	return result

}

func partation(num []int, left, right int) int {
	if left == right {
		return right
	}
	if left < right {
		// 1.找到基准元素
		base := num[left]
		l := left
		r := right
		for {
			// 2. 如果右侧的值大于base ，尾指针 向前移动
			for num[r] >= base && l < r {
				r--
			}
			// 3.如果左侧的值小于base , 头指针向后移动
			for num[l] <= base && l < r {
				l++
			}
			// 交换一下
			if l >= r {
				//fmt.Println("break")
				break

			}
			num[l], num[r] = num[r], num[l]
		}
		// 基准值为找到的那个值
		num[left] = num[l]
		num[l] = base
		return l
	}
	return -1
}
```
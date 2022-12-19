![煎饼反转.PNG](https://pic.leetcode-cn.com/133cd86f79792751c798c59b521b7bc79c6abe8e4495c5244affb76417d00d82-%E7%85%8E%E9%A5%BC%E5%8F%8D%E8%BD%AC.PNG)

func pancakeSort(A []int) []int {

	kArr := make([]int,0)

	if A == nil || len(A) == 0{
		return kArr
	}

	if _Comparator(A) {  //比较器，看看最后排序是否正确
		return kArr
	}


	start, end := 0, len(A)-1
	maxIndex := -1
	for ;start < end ; {
		maxIndex = _FindMax(A,start, end)  //1. 寻找区块最大值
		_ReverseArr(A, start, maxIndex) // 2. 反转指定区间的数组
		kArr = append(kArr, maxIndex+1) // 3. 把maxIndex+1添加到kArr数组中
		_ReverseArr(A, start, end) // 4. 再反转start到end指定区间的数组
		kArr = append(kArr, end+1) // 5. 增长数组
		end -- //4
	}
	return kArr
}

//有序返回true
func _Comparator(A []int) bool {
	for i := len(A)-1; i > 0; i--{
		if A[i] < A[i-1]{
			return false
		}
	}
	return true
}

//指定范围内寻找最大值
func _FindMax(A []int, start, end int) int {
	if start >= end {
		return -1
	}


	maxIndex := start  //0
	for i := start; i <= end; i++{  //0
		if A[maxIndex] < A[i] {  //[0] < A[1]
			maxIndex = i
		}
	}

	return maxIndex
}

//指定范围内反转数组
func _ReverseArr(A []int, start, end int) {
	if start >= end{
		return
	}

	for; start < end; {
		tmp := A[end]
		A[end] = A[start]
		A[start] = tmp
		start++
		end--
	}
}


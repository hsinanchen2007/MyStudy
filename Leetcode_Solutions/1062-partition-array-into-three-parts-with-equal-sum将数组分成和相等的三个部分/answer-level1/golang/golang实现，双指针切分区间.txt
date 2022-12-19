golang实现，双指针切分区间

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 双指针切分区间,尝试将数组切分成 [0,i] (i,j) [j,len(A)-1]三部分
// 时间复杂度：O(n)  空间复杂度：O(1)

func canThreePartsEqualSum(A []int) bool {
	sum := 0
	for _, num:=range A {
		sum += num
	}

	if len(A)<3 || sum%3!=0 {
		return false
	}

	// 使用双指针'i','j', 尝试将数组A划分成 [0,i] (i,j) [j,len(A)-1]三部分
	var i, j int
	target := sum/3
	temp1 := 0
	temp2 := 0
	for i=0; i<len(A); i++ {
		temp1 += A[i]
		if temp1==target {
			break
		}
	}

	for j=len(A)-1; j>=0; j-- {
		temp2 += A[j]
		if temp2==target {
			break
		}
	}

	if i+1<j {
		return true
	}
	return false
}
```

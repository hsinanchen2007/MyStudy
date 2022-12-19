### 解题思路
基于L和M，创建两个slice：lsum和msum，分别保存以某个数字为起点的，长度分别为L和M的元素之和
然后两层循环，分别求lsum[i]和msum[j]的和，保存最大值即可


### 代码

```golang
func max(i, j int) int{
	if i > j {
		return i
	} 
	return j
	
}

func maxSumTwoNoOverlap(A []int, L int, M int) int {
	lsum := make([]int, len(A)-L+1)
	msum := make([]int, len(A)-M+1)
	for i := 0; i < L; i++ {
		lsum[0] = lsum[0]+A[i]
	}
	for i := 0; i < M; i++ {
		msum[0] = msum[0]+A[i]
	}
	for i := 1; i < len(A)+1-L; i++ {
		lsum[i] = lsum[i-1]-A[i-1]+A[i+L-1]
	}

	for i := 1; i < len(A)+1-M; i++ {
		msum[i] = msum[i-1]-A[i-1]+A[i+M-1]
	}
	ret := 0
	for i := 0; i < len(lsum); i++ {
		for j := 0; j < len(msum); j++ {
			if j+M <= i || j >= i+L {
				ret = max(lsum[i]+msum[j], ret)
			}
		}

	}
	return ret
}
```
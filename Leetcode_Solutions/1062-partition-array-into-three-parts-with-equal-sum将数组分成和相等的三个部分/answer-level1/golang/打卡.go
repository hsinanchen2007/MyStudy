### 解题思路
打卡

### 代码

```golang
func canThreePartsEqualSum(A []int) bool {
	sum := 0
	for i := 0; i < len(A); i++ {
		sum += A[i]
	}
	if sum%3 != 0 {
		return false
	}

	partSum := sum / 3
	lastPartIndex := -1
	blockCount := 0
	tmpSum := 0
	for i := 0; i < len(A); i++ {
		tmpSum += A[i]
		if tmpSum == partSum {
			lastPartIndex = i
			blockCount++
			tmpSum = 0
		}

		if blockCount == 2 {
			break
		}
	}
	if blockCount == 2 && lastPartIndex < len(A)-1 {
		tmp := 0
		for i := lastPartIndex + 1; i < len(A); i++ {
			tmp += A[i]
		}
		if tmp == partSum {
			return true
		}
	}

	return false
}
```
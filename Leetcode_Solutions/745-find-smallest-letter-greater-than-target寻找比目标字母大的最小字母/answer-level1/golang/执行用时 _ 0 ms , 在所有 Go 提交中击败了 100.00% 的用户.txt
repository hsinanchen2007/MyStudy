### 解题思路

### 代码

```golang
func nextGreatestLetter(letters []byte, target byte) byte {
    if letters[0] > target || letters[len(letters)-1] <= target {
		return letters[0]
	}

	low, high := 0, len(letters)-1

	var mid int
	for low <= high {
		mid = low + (high-low)/2
		if letters[mid] <= target { // 找到目标值的
			if mid == len(letters)-1 {
				return letters[len(letters)-1]
			}
			if letters[mid+1] > target {
				return letters[mid+1]
			} else {
				low = mid + 1
			}
		} else {
			high = mid - 1
		}
	}

	return ' '
}
```
```
func sortArrayByParity(A []int) []int {
	for left, right := 0, len(A) - 1; left < right; {
        //找到左边的奇数
		for left < right && A[left] % 2 == 0  {
			left ++
		}
        //找到右边的偶数
		for right > left && A[right] % 2 != 0  {
			right --
		}
        //交换
		A[left], A[right] = A[right], A[left]
	}
	return A
}
```

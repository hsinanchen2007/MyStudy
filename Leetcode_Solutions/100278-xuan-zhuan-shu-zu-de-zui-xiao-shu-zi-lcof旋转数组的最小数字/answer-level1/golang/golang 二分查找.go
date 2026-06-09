```
func minArray(numbers []int) int {
	low := 0
	high := len(numbers) - 1
	for numbers[low] >= numbers[high] && low < high {
		mid := (low + high) / 2
		if numbers[mid] > numbers[low] {
			low = mid + 1
		} else if numbers[mid] < numbers[low] {
			high = mid
		} else if numbers[mid] == numbers[low] {
			low++
		}
	}
	return numbers[low]
}
```

二分查找最短半径得解。当前半径可以覆盖所有房子， high = mid， else low = mid + 1

注意
- houses和heaters需要自己排序
```
func findRadius(houses []int, heaters []int) int {
	sort.Ints(houses)
	sort.Ints(heaters)
	low, high := 0, 1000000000
	for low < high {
		mid := low + (high - low) / 2
		hIdx := 0
		left, right := heaters[hIdx] - mid, heaters[hIdx] + mid
		var i int
		for i = 0; i < len(houses); {
			if houses[i] < left {
				break
			} else if houses[i] > right {
				hIdx++
				if hIdx >= len(heaters) {
					break
				}
				left, right = heaters[hIdx] - mid, heaters[hIdx] + mid
				continue
			}
			i++
		}
		if i == len(houses) {
			high = mid
		} else {
			low = mid + 1
		}
	}
	return low
}
```

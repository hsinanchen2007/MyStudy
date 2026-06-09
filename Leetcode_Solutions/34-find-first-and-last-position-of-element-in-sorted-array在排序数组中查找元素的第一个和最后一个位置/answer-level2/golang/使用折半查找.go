### 解题思路
1、折半查找，这里要注意边界情况，否者可能会出现死循环
2、在寻找中点时，尽量不要使用 mid = (low + high) /2，如果数字过大，可能会导致内存
溢出
3、使用 2>>1 移位比 除2的速度快

### 代码

```golang
func searchRange(nums []int, target int) []int {
	var (
		length  int
		low     int
		high    int
		mid     int
		pos     int
		lowPos  int
		highPos int
	)

	length = len(nums)
	ret := []int{-1, -1}
	pos, lowPos, highPos, mid = -1, -1, -1, 0
	low, high = 0, length-1

	if length > 0 {
		for {
			if low+1 >= high {
				if nums[high] == target {
					pos = high
				} else if nums[low] == target {
					pos = low
				} else {
					pos = -1
				}
				break
			}

			// 尽量不要使用 mid = (low + high) / 2 这种形式，可能会导致内存溢出
			mid = low + (high-low)>>1

			if nums[mid] > target {
				high = mid
			} else if nums[mid] < target {
				low = mid
			} else {
				pos = mid
				break
			}
		}
	}

	if pos != -1 {
		lowPos, highPos = pos, pos
		for i := pos; i >= 0; i-- {
			if nums[i] == target {
				lowPos = i
			}
		}
		for j := pos; j <= length-1; j++ {
			if nums[j] == target {
				highPos = j
			}
		}

		ret[0], ret[1] = lowPos, highPos
	}

	return ret

}
```
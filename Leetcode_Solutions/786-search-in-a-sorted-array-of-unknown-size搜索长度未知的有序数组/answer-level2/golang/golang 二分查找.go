### 解题思路
简单的二分查找

### 代码

```golang

func search(reader ArrayReader, target int) int {
	lo := 0
	hi := math.MaxInt32
	for lo < hi {
		middle := (lo + hi) / 2
		if reader.get(middle) == 2147483647 {
			hi = middle - 1
			continue
		}
		if reader.get(middle) == target {
			return middle
		} else if reader.get(middle) > target {
			hi = middle
		} else if reader.get(middle) < target {
			lo = middle + 1
		}
	}
	if reader.get(lo) == target {
		return lo
	}
	return -1
}
```
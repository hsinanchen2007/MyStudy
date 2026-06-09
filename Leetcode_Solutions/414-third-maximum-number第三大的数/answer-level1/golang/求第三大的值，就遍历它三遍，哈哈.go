### 代码

```golang
func thirdMax(nums []int) int {
    dict := make(map[int]int, 3)
	dict[0] = math.MinInt64

	for _, values := range nums {
		if values > dict[0] {
			dict[0] = values
		}
	}
	for _, values := range nums {
		if values < dict[0] {
			v, exist := dict[1]
			if !exist {
				dict[1] = values
			} else {
				if values > v {
					dict[1] = values
				}
			}
		}
	}
	for _, values := range nums {
		if values < dict[1] {
			v, exist := dict[2]
			if !exist {
				dict[2] = values
			} else {
				if values > v {
					dict[2] = values
				}
			}
		}
	}
	if len(dict) == 3 {
		return dict[2]
	} else {
		return dict[0]
	}
}
```
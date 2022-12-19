### 解题思路
此处撰写解题思路

### 代码

```golang
func minSwaps(data []int) int {
	if len(data) == 0 {
		return 0
	}
	num := 0
	sum := make([]int, len(data), len(data))
	if data[0] == 1 {
		sum[0] = 1
	} else {
		sum[0] = 0
	}
	for i := 0; i < len(data); i++ {
		if data[i] == 1 {
			num++
		}
		if i >= 1 {
			if data[i] == 1 {
				sum[i] = sum[i-1] + 1
			} else {
				sum[i] = sum[i-1]
			}
		}
	}

	if num <= 1 {
		return 0
	}

	max := sum[num-1]

	for i := num ; i < len(data); i++ {
		n := sum[i] - sum[i-num]
		if max < n {
			max = n
		}
	}

	return num - max
}

```
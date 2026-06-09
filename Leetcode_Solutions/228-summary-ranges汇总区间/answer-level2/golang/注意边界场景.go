### 解题思路
此处撰写解题思路

### 代码

```golang
func summaryRanges(nums []int) []string {
	n := len(nums)
	if n == 0 {
		return []string{}
	}

	if n == 1 {
		return []string{strconv.Itoa(nums[0])}
	}

	r := make([]string, 0)
	start := 0
	for i := 1; i < n; i++ {
		if nums[i]-nums[i-1] > 1 {
			if i-start-1 == 0 {
				r = append(r, strconv.Itoa(nums[start]))
			} else {
				r = append(r, fmt.Sprintf("%s->%s", strconv.Itoa(nums[start]), strconv.Itoa(nums[i-1])))
			}

			start = i
		}
	}
	if start == n-1 {
		r = append(r, strconv.Itoa(nums[n-1]))
	} else {
		r = append(r, fmt.Sprintf("%s->%s", strconv.Itoa(nums[start]), strconv.Itoa(nums[n-1])))
	}

	return r
}

```
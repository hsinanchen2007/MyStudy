### 解题思路
此处撰写解题思路

### 代码

```golang

func findMissingRanges(nums []int, lower int, upper int) []string {
	n := len(nums)
	if n == 0 {
		if lower != upper {
			return []string{fmt.Sprintf("%s->%s", strconv.Itoa(lower), strconv.Itoa(upper))}
		}
		return []string{fmt.Sprintf("%s", strconv.Itoa(lower))}

	}

	r := make([]string, 0)

	if nums[0]-lower == 1 {
		r = append(r, fmt.Sprintf("%s", strconv.Itoa(lower)))
	}
	if nums[0]-lower >= 2 {
		r = append(r, fmt.Sprintf("%s->%s", strconv.Itoa(lower), strconv.Itoa(nums[0]-1)))
	}

	for i := 0; i < n-1; i++ {
		t := getDiff(nums[i], nums[i+1])
		if t != "" {
			r = append(r, t)
		}
	}

	if upper-nums[len(nums)-1] == 1 {
		r = append(r, fmt.Sprintf("%s", strconv.Itoa(upper)))
	}

	if upper-nums[len(nums)-1] >= 2 {
		r = append(r, fmt.Sprintf("%s->%s", strconv.Itoa(nums[len(nums)-1]+1), strconv.Itoa(upper)))
	}
	return r
}

func getDiff(a, b int) string {
	if b-a < 2 {
		return ""
	}
	if b-a == 2 {
		return strconv.Itoa(a + 1)
	}

	return fmt.Sprintf("%s->%s", strconv.Itoa(a+1), strconv.Itoa(b-1))

}

```
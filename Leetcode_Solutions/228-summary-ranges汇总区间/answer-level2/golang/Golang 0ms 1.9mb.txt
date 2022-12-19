### 解题思路
此处撰写解题思路

### 代码

```golang
func summaryRanges(nums []int) []string {
	res := make([]string, 0)
	exist := make(map[string]struct{})
	if len(nums) == 0 {
		return res
	}
	start, end, lastNum := nums[0], nums[0], nums[0]-1
	for _, v := range nums {
		if v == lastNum+1 {
			end = v
			lastNum = v
		} else {
			if start == end {
				exist[fmt.Sprintf("%d", start)] = struct{}{}
				res = append(res, fmt.Sprintf("%d", start))
			} else {
				exist[fmt.Sprintf("%d->%d", start, end)] = struct{}{}
				res = append(res, fmt.Sprintf("%d->%d", start, end))
			}
			start, end, lastNum = v, v, v
		}
	}
	if start == end {
		if _, ok := exist[fmt.Sprintf("%d", start)]; !ok {
			res = append(res, fmt.Sprintf("%d", start))
		}
	} else {
		if _, ok := exist[fmt.Sprintf("%d->%d", start, end)]; !ok {
			res = append(res, fmt.Sprintf("%d->%d", start, end))
		}
	}
	return res
}
```
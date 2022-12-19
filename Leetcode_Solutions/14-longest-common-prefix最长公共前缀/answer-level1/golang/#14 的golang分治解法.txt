```
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	return doLongestCommonPrefix(strs, 0, len(strs)-1)
}

func doLongestCommonPrefix(strs []string, l int, r int) string {
	if l == r {
		return strs[l]
	}
	mid := (l + r) / 2
	lcpLeft := doLongestCommonPrefix(strs, l, mid)
	lcpRight := doLongestCommonPrefix(strs, mid+1, r)
	return commonPrefix(lcpLeft, lcpRight)
}

func commonPrefix(left, right string) string {
	min := math.Min(float64(len(left)), float64(len(right)))
	for i:= 0; i < int(min); i ++ {
		if left[i] != right[i] {
			return left[0:i]
		}
	 }
	 return left[0: int(min)]
}
```

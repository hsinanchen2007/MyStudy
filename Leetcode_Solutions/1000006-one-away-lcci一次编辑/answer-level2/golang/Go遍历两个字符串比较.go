两个字符串的长度相差超过1就返回false
长度相同的两个字符串：只会出现1次或0次的字符不相等
长度不相等的两个字符串：在某次不相等后，把长的字符串的下标+1后，后面的子串必定相等
```
func oneEditAway(first string, second string) bool {
	if math.Abs(float64(len(first))-float64(len(second))) > 1 { //长度相差超过1就返回
		return false
	}
	length1, length2 := len(first), len(second)
	differ := 0 //记录两个字符串比较有多少次的不同
	i, j := 0, 0
	for i < length1 && j < length2 {
		if first[i] != second[j] {
			differ++
			if length1 > length2 { //出现不同的情况，就把长的那个下标++，正常来说，下一个会相等，并且之后的字符也会相等
				i++
				continue
			} else if length1 < length2 {
				j++
				continue
			}
		}
		i++
		j++
	}

	return differ <= 1
}

```

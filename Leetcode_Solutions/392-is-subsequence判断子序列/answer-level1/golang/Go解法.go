双指针。内存循环遍历t，找到外层的对应s[i],立即跳出本次循环，并且记录当前循环已经迭代的位置，下次进入循环的时候，从此位置+1开始
```
func isSubsequence(s string, t string) bool {
    if s == ""{
		return true
	}
    ls := len(s)
	lt := len(t)
	var flag = false
	tmp := 0
	for i := 0; i < ls; i++ {
		for j := tmp; j < lt; j++ {
			if s[i] == t[j] {
				flag = true
				tmp = j + 1
				break
			}
		}
		if !flag || i+1 == ls {
			return flag
		} else {
			flag = false
		}
	}
	return flag
}
```

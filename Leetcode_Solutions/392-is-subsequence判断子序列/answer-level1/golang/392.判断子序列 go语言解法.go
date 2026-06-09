### 解题思路

采用双指针，一个指针指向s，一个指针遍历t，如果当前两指针所指值相同，则s指针+1，若t指针遍历完后，s指针仍未到s的最后一个元素处，则说明s不是t的子串，返回false。

### 代码

```golang
func isSubsequence(s string, t string) bool {
	if len(s) == 0 {
		return true
	}
	ps,pt := 0,0
	for pt < len(t) {
		if s[ps] == t[pt] {
			ps++
		}
		if ps == len(s) {
			return true
		}
		pt++
	}
	return false
}
```
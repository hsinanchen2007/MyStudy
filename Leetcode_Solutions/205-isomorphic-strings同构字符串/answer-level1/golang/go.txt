### 解题思路


### 代码

```golang
func isIsomorphic(s string, t string) bool {
	sb := []byte(s)
	st := []byte(t)

	if len(sb) == 0 && len(st) == 0 {
		return true
	}

	if len(sb) != len(st) {
		return false
	}

	for i := 0; i < len(sb); i++ {
		if bytes.IndexByte(sb, sb[i]) != bytes.IndexByte(st, st[i]) {
			return false
		}
	}
	
	return true
}
```
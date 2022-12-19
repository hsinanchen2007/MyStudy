### 解题思路

创建map，遍历杂志，把杂志中的字母以及出现了几次都存放在map中，再遍历赎金信，每遇到一个字母，map中相应字母的次数减1，如果某个字母在map中不存在，或存在次数为0了，则返回false，否则遍历完成返回true

### 代码

```golang
func canConstruct(ransomNote string, magazine string) bool {
	m := make(map[byte]int)
	for i := 0;i < len(magazine);i++ {
		if _,ok := m[magazine[i]];ok {
			m[magazine[i]] += 1
		}else {
			m[magazine[i]] = 1
		}
	}
	for j := 0;j < len(ransomNote);j++ {
		if _,ok := m[ransomNote[j]];ok {
			if m[ransomNote[j]] < 1 {
				return false
			}else {
				m[ransomNote[j]] -= 1
			}
		}else {
			return false
		}
	}
	return true
}
```
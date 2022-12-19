### 解题思路

用哈希表，把s中出现的字母和次数存进去，再遍历t，如果t中字母不在哈希表中，返回当前下标，如果遇哈希表中存在的，则在表中的次数减1，若次数变为-1，则返回当前下标。

### 代码

```golang
func findTheDifference(s string, t string) byte {
	hash := make(map[byte]int)
	for i := 0;i < len(s);i ++ {
		if _,ok := hash[s[i]] ; ok {
			hash[s[i]] += 1
		}else {
            hash[s[i]] = 1
        }
	}
    var result byte
	for j := 0;j < len(t);j ++ {
        
		if _,ok := hash[t[j]] ; ok {
			hash[t[j]] -= 1
            if hash[t[j]] < 0 {
                result = t[j]
            }
		}else {
            result = t[j]
        }
	}
    return result
}
```
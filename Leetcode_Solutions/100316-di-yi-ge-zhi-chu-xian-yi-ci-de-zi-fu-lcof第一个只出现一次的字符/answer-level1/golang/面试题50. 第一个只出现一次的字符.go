### 解题思路
此处撰写解题思路

### 代码

```golang
func firstUniqChar(s string) byte {
	res := make([]int, 27)
	for i := 0; i < len(s); i++ {
		res[s[i]-'a'] ++
	}
	for i := 0; i < len(s); i++ {
		if res[s[i]-'a']  == 1{
			return s[i]
		}
	}
	return byte(' ')

}
```
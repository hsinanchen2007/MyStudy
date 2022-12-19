### 解题思路
此处撰写解题思路

### 代码

```golang
func findTheDifference(s string, t string) byte {
	datas:=[26]int{}
	ls := len(s)
	i := 0
	for i < ls+1 {
		if i < ls {
			datas[s[i]-'a']--
		}
		datas[t[i]-'a']++
		i++
	}
	for j:=0;j<26;j++{
		if datas[j]==1{
			return byte(j)+'a'
		}
	}
	return 0
}
```
### 解题思路
字典的思路，把字符出现的频率统计出来，然后比对是不是两个字符串中每个字符出现的频率相同，相同返回True，不同的话返回False。如果两个字符串不一样长，我们就可以直接返回false，这波必不可能true。

isAnagram2是我稍微优化了一下空间之后的方法，我发现可以不用开两个map，在一个里s出现加，t出现减，最后只要看看map里有没有哪个key的value是非0元，没有就可以返回True，有的话就是False。

//又是好蠢的办法大佬莫嫌弃orz

### 代码

```golang
func isAnagram(s string, t string) bool {
    map1 := make(map[string]int)
	map2 := make(map[string]int)
	if len(s)!=len(t){
		return false
	}
	for i:=0;i<len(s);i++{
		map1[s[i:i+1]]+=1
		map2[t[i:i+1]]+=1
	}
	for key:=range map1{
		if map1[key]!=map2[key]{
			return false
		}
	}
	return true
}

func isAnagram2(s string, t string) bool {
    map1 := make(map[string]int)
	if len(s)!=len(t){
		return false
	}
	for i:=0;i<len(s);i++{
		map1[s[i:i+1]]+=1
		map1[t[i:i+1]]-=1
	}
	for key:=range map1{
		if map1[key]!=0{
			return false
		}
	}
	return true
}
```
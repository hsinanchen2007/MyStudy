一维数组统计chars字母出现的频率，然后遍历words，当words[i][j]位置的字符出现，chars相应位置减一，等到words[i]遍历结束，再将一维数组加回来。
时间复杂度：89.53；空间复杂度：100%
```
func countCharacters(words []string, chars string) int {
	arr:=make([]int,26)
	for i:=0;i<len(chars);i++{
		arr[chars[i]-'a']++
	}
	res:=0
	for i:=0;i<len(words);i++{
		flag:=0
		temp:=len(words[i])-1
		for j:=0;j<len(words[i]);j++{
			arr[words[i][j]-'a']--
			if arr[words[i][j]-'a']<0 {
				flag=1
				temp=j
				break
			}
		}
		for j:=0;j<=temp;j++{
			arr[words[i][j]-'a']++
		}
		if flag==0 {
			res+=len(words[i])
		}
	}
	return res
}
```


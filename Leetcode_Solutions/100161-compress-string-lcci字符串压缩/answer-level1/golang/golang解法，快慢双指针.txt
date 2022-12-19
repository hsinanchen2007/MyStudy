golang解法，快慢指针
github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 双指针取连续字符
// 时间复杂度：O(n)  空间复杂度：O(1)

func compressString(S string) string {

	if len(S)==0 {
		return ""
	}

	str := ""
	cnt := 1
	i := 0
	j := 1
	
	for ; j<len(S); j++ {
		if S[i:i+1]==S[j:j+1]{
			cnt++
		}else {
			str = str + S[i:i+1] + strconv.Itoa(cnt)
			i = j
			cnt = 1
		}
	}
	str = str + S[i:i+1] + strconv.Itoa(cnt)

	if len(str)<len(S){
		return str
	}

	return S	
}
```

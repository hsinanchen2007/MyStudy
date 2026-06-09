对第二个字符串组做桶排序
再对一个字符串组做依次处理，感觉时间复杂度上差不多应该是最佳了
执行用时和我预料的差不多，在时间复杂度上超过100%了
```
func numSmallerByFrequency(queries []string, words []string) []int {
	var res []int
	w:=make([]int,11)
	for _,v:=range words{
		w[getFre(v)]++
	}
	for _,v:=range queries{
		sum:=0
		tmp:=getFre(v)
		for i:=1;i<len(w);i++{
			if i>tmp {
				sum+=w[i]
			}
		}
		res= append(res, sum)
	}
	return res
}

func getFre(s string) int {
	res:=0
	temp:=s[0]-'a'
	for i:=0;i<len(s);i++{
		if s[i]-'a'<temp {
			temp=s[i]-'a'
		}
	}
	for i:=0;i<len(s);i++ {
		if s[i]=='a'+temp{
			res++
		}
	}
	return res
}
```

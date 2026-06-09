第一次没有看到类似"[[]]"的嵌套结构，因此写了一版只含一层的"[]"的字符串解析
于是后面看到了双层"[]"的嵌套结构后，想到了递归实现，同时想到了栈
但这里不需要栈，只需要记录与"["符号相对应的"]"出现的位置即可
于是就有了下面的这种解法


```golang
func decodeString(s string) string {
	var res strings.Builder
	for i:=0;i<len(s);i++{
		if s[i]<'0'||s[i]>'9'{
			res.WriteByte(s[i])
		}else{
			j:=i+1
			for j<len(s){
				if s[j]=='['{
					break
				}
				j++
			}
			flag:=1
			k:=j+1
			for k<len(s){
				if s[k]=='['{
					flag++
				}
				if s[k]==']'{
					flag--
					if flag==0{
						break
					}
				}
				k++
			}
			nums,_:=strconv.Atoi(s[i:j])
			str:=decodeString(s[j+1:k])
			for m:=0;m<nums;m++{
				res.WriteString(str)
			}
			i=k
		}
	}
	return res.String()
}
```

再补充个go的正则表达式实现吧

```golang
func decodeString2(s string) string {
	res:=regexp.MustCompile("\\d+\\[\\w+]")
	res2:=regexp.MustCompile("\\d+")
	res3:=regexp.MustCompile("\\[\\w+]")
	for res.MatchString(s){
		s = res.ReplaceAllStringFunc(s, func(tes string) string {
			var temp strings.Builder
			nums, _ := strconv.Atoi(res2.FindAllString(tes, -1)[0])
			words := res3.FindAllString(tes, -1)[0]
			word := words[1 : len(words)-1]
			for i := 0; i < nums; i++ {
				temp.WriteString(word)
			}
			return temp.String()
		})
	}
	return s
}
```
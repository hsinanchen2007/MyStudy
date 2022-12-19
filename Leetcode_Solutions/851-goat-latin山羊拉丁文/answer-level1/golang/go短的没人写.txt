```
func toGoatLatin(S string) string {
	slice := strings.Fields(S)
	//用作后缀(ma+第一个a)
	aslice := []string{"maa"}
	for i:=0;i<len(slice);i++{
		//看首字母
		switch slice[i][0] {
		//前缀新单词放在后缀"aaaaaa"前面
		case 'a', 'e', 'i', 'o', 'u','A','E','I','O','U':
			aslice = append([]string{slice[i]}, aslice...)
		default:
			aslice = append([]string{slice[i][1:] + slice[i][:1] }, aslice...)
		}
		//前缀新单词和后缀"aaaaaa"组合为新的羊文
		slice[i] = strings.Join(aslice, "")
		//把前缀新单词删了,再加一个"a"下回用
		aslice = append(aslice[1:], "a")
	}
	//空格分隔,组合
	return strings.Join(slice," ")
}

```

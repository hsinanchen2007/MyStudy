```
//方法一： 暴力求解
func longestCommonPrefix(strs []string) string {
	stest:=shortest(strs)
	for i,r:= range stest{
		for j:= range strs{
			if strs[j][i] != byte(r){
				return stest[:i]
			}

		}
	}

	return stest

}
//shack,short,shake,shy

func shortest(s []string)string{
	if len(s) == 0{
		return ""
	}
	short:=s[0]
	for i:=1;i<len(s);i++{
		if len(s[i]) < len(short){
			short = s[i]
		}
	}
	return short
}
//水平扫描法
func longestCommonPrefix2(strs []string) string {
	if len(strs)==0{
		return ""
	}
	prefix:= strs[0]
	for i:=1;i<len(strs);i++{
		for !strings.HasPrefix(strs[i],prefix){
			prefix:=prefix[:len(prefix)-1]
			if prefix == ""{
				return ""
			}
		}
	}
	return prefix
}
```
第一种没啥好解释的，看代码即可。第二种是官方题解第一种方法的golang翻译版。
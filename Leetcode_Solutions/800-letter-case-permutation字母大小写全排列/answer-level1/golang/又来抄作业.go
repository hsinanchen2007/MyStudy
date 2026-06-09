### 解题思路
此处撰写解题思路
仔细理解了，就觉得也没那么难了，，，
### 代码

```golang
func letterCasePermutation(S string) []string {
	res:=make([]string,0)
	sRune:=[]rune(S)
	helpLetterCasePermutation(&res,sRune,0)
	return res
}
//如果字符串中字母的个数是n，则最后会有 2的n次方个字符串 S （一路走来被改变了其中的字母大小写），需要一并同时执行 2^n 个 执行*res=append(*res,string(newS))
func helpLetterCasePermutation(res *[]string,S []rune,index int)[]string{
	if index== len(S){
		newS:=make([]rune, len(S))
		copy(newS,S)
		*res=append(*res,string(newS))
		return *res
	}
	e:=S[index]
	helpLetterCasePermutation(res,S,index+1)
	if !('0'<=e&&e<='9'){
		//如果第i位是字母，则将其变为另一种（大写或者小写）继续看后面的字母
		S[index]^=32
		helpLetterCasePermutation(res,S,index+1)
	}
	return *res
}
```
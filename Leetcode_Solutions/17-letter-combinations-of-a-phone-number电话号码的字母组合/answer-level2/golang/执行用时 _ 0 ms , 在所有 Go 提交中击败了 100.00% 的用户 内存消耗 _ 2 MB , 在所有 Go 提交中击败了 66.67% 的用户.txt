排列组合问题，递归回溯
代码如下：
```
func letterCombinations(digits string) []string {
	var res []string
	if len(digits)==0 {
		return res
	}
	mapping:=make(map[byte][]string)
	mapping['2']=[]string{"a","b","c"}
	mapping['3']=[]string{"d","e","f"}
	mapping['4']=[]string{"g","h","i"}
	mapping['5']=[]string{"j","k","l"}
	mapping['6']=[]string{"m","n","o"}
	mapping['7']=[]string{"p","q","r","s"}
	mapping['8']=[]string{"t","u","v"}
	mapping['9']=[]string{"w","x","y","z"}
	getCombinations(digits,mapping,0,&res,"")
	return res
}
func getCombinations(digits string,mapping map[byte][]string,n int,res *[]string,temp string){
	if n==len(digits) {
		*res= append(*res, temp)
		return
	}
	for i:=0;i<len(mapping[digits[n]]);i++{
		getCombinations(digits,mapping,n+1,res,temp+mapping[digits[n]][i])
	}
}
```

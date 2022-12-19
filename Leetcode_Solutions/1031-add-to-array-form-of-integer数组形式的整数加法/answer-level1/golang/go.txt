### 解题思路
此处撰写解题思路

### 代码

```golang
func addToArrayForm(A []int, K int) []int {
	res:=[]int{}
	for K>0{
		res= append(res, K%10)
		K/=10
	}
	for i:=0;i< len(res)/2;i++{
		res[i],res[len(res)-1-i]=res[len(res)-1-i],res[i]
	}
	var short,long []int
	if len(A)> len(res){
		long,short=A,res
	}else{
		long,short=res,A
	}
	tmp:=0
	ans:=make([]int, len(long))
	for i:=len(short)-1;i>=0 ;i--{
		v:=short[i]+long[i+len(long)-len(short)]+tmp
		ans[i+len(long)-len(short)]=v%10
		tmp=v/10
	}
	long=long[:len(long)-len(short)]
	for i:=len(long)-1;i>=0 ;i--{
		v:=long[i]+tmp
		ans[i]=v%10
		tmp=v/10
	}
	if tmp>0{
		return append([]int{tmp},ans...)
	}
	return ans
}
```
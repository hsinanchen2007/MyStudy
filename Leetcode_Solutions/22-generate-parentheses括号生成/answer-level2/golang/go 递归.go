a       记录剩余的 "(" 个数
b       剩余的 ")" 个数
temp    当前已有串中的还未配对的 "(" 个数
当（ 进时，temp+1，a-1，b不变
当 ）进时，temp-1，a不变，b-1
temp [0,n-1]时，可以加入（
temp (0,n]时，可以加入 ）


```
func generateParenthesis(n int) []string {
	res := []string{}
	a := n-1
	b := n
	temp := 1
	r := "("
	ccc(a,b,temp,n,r,&res)
	return res
}
func ccc(a,b,temp,n int,res string,result *[]string){
	if a > 0 || b > 0{
		if temp == 0{
			res += "("
			ccc(a-1,b,1,n,res,result)
		}else if temp == n{
			res += ")"
			ccc(a,b-1,temp-1,n,res,result)
		}else{
			q := res
			if a > 0{
				res += "("
				ccc(a-1,b,temp+1,n,res,result)
			}
			q += ")"
			ccc(a,b-1,temp-1,n,q,result)
		}
	}else{
		*result = append(*result, res)
	}
}
```

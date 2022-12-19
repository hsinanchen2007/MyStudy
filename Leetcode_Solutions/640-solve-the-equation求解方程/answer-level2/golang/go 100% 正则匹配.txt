### 解题思路
通过正则匹配，将数字，x（包含正负号）分开
![1576662392(1).png](https://pic.leetcode-cn.com/cd240fd66269be8ab20d6453af57bc694727e0203fee85fcb3bc5c16e5a7d5c9-1576662392\(1\).png)

### 代码

```golang
func solveEquation(equation string) string {
	exprs:=strings.Split(equation,"=")
	xl,nl:=getValue(exprs[0])
	xr,nr:=getValue(exprs[1])
	x:=xl-xr
	n:=nr-nl
	if x==0&&n==0{
	return "Infinite solutions"
	}else if x==0&&n!=0{
	return "No solution"
	}else {
	k:=n/x
	return "x="+strconv.Itoa(k)
	}
}
func getValue(expr string) (int,int) {
	re,_:=regexp.Compile("[+-]?[\\d]*[x]?")
	ss := re.FindAllString(expr, -1)
	xVal:=0
	nVal:=0
	for _,s:=range ss{
		if strings.Contains(s,"x"){
			kk:=s[:len(s)-1]
			if kk==""||kk=="+"{
				xVal+=1
			}else if kk=="-"{
				xVal+=-1
			}else {
				n,_:=strconv.Atoi(kk)
				xVal+=n
			}
		}else {
			n,_:=strconv.Atoi(s)
			nVal+=n
		}
	}
	return xVal,nVal
}
```
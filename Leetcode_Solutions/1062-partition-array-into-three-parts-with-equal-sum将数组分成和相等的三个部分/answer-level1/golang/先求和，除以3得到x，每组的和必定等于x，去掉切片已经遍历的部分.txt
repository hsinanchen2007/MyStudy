### 解题思路
此处撰写解题思路

### 代码

```golang
func canThreePartsEqualSum(A []int) bool {
	count:=0
	tmp:=0
	target:=0
	for _,v:=range A{
		target+=v
	}
	if target%3!=0{
		return false
	}else{
		target/=3
	}
	for i:=0;i< len(A);i++{
		tmp+=A[i]
		if tmp==target{
			if i== len(A)-1{
				A=A[:0]
			}else{
				A=A[i+1:]
			}
			i=-1
			count++
			tmp=0
			if count==3{
				break
			}
		}
	}
	if count!=3{
		return false
	}else{
		rest:=0
		for _,v:=range A{
			rest+=v
		}
		if rest!=0{
			return false
		}
	}
	
	return true
}
```
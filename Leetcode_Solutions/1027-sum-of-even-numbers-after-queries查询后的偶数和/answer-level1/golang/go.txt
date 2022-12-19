### 解题思路
此处撰写解题思路

### 代码

```golang
func sumEvenAfterQueries(A []int, queries [][]int) []int {
	res:=[]int{}
	doubles:=0
	for _,v:=range A{
		if v%2==0{
			doubles+=v
		}
	}
	for i:=0;i< len(queries);i++{
		val:=queries[i][0]
		index:=queries[i][1]
		if A[index]%2!=0&&val%2!=0{
			doubles+=A[index]+val
		}else if A[index]%2==0&&val%2==0{
			doubles+=val
		}else if A[index]%2==0&&val%2!=0{
			doubles-=A[index]
		}
		res= append(res,doubles )
		A[index]=A[index]+val
	}
	return res
}
```
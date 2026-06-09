### 解题思路
此处撰写解题思路

### 代码

```golang
func sortArrayByParityII(A []int) []int {
	single:=make([]int,0)
	double:=make([]int,0)
	for _,v:=range A{
		if v%2==0{
			double= append(double, v)
		}else{
			single= append(single, v)
		}
	}
	
	for i:=0;i< len(double);i++{
		A[i*2]=double[i]
		A[i*2+1]=single[i]
	}
	return A
}
```
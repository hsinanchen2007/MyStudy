### 解题思路
此处撰写解题思路

### 代码

```golang
func imageSmoother(M [][]int) [][]int {
	if len(M)==0{
		return nil
	}
	N:=make([][]int, len(M))
	for i:=0;i< len(M);i++{
		tmp:=make([]int,0)
		for j:=0;j< len(M[0]);j++{
			res:=0
			count:=0
			for x:=i-1;x<=i+1;x++{
				for y:=j-1;y<=j+1;y++{
					if x<0{
						break
					}
					a:=findSmoother(M,x,y)
					res+=a[0]
					count+=a[1]
				}
			}
			if count>0{
				tmp= append(tmp, res/count)
			}else{
				tmp= append(tmp, 0)
			}
		}
		N[i]=tmp
	}
	return N
}
func findSmoother(M [][]int,i int,j int,) []int {
	if 0<=i&&i< len(M)&&0<=j&&j< len(M[0]){
		return []int{M[i][j],1}
	}
	return []int{0,0}
}

```
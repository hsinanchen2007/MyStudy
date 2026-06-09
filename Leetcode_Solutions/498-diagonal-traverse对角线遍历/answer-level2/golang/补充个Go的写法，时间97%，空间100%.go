以数组的左边界和下边界遍历整个数组，设置标识flag适当反转数组即可

```golang
func findDiagonalOrder(matrix [][]int) []int {
    if len(matrix)==0{
        return []int{}
    }
	var res,temp []int
	row,col,flag,i,j:=len(matrix),len(matrix[0]),0,0,0
	if row==1{
		return matrix[0]
	}
	for j<=col-1{
		m,n:=i,j
		temp=append(temp,matrix[i][j])
		for m!=0&&n!=col-1 {
			m--
			n++
			temp=append(temp,matrix[m][n])
		}
		if flag%2!=0{
			reverse(temp)
		}
		res=append(res,temp...)
		flag++
		temp=temp[:0]
		if i!=row-1{
			i++
		}else{
			j++
		}
	}
	return res
}


func reverse(arr []int)  {
	i,j:=0,len(arr)-1
	for i<j {
		arr[i],arr[j]=arr[j],arr[i]
		i++
		j--
	}
}
```
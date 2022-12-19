补充Go的并查集写法（代码参考题解中的并查集C++实现）

```golang
func minSwapsCouples(row []int) int {
	arr:=make([]int,len(row)/2)
	for k,_:=range arr{
		arr[k]=k
	}
	for i:=0;i<len(row);i+=2{
		t1,t2:=row[i]/2,row[i+1]/2
		combineC(arr,t1,t2)
	}
	count:=0
	for i:=0;i<len(arr);i++{
		if findF(arr,i)==i {
			count++
		}
	}
	return len(arr)-count

}
func findF(arr []int, i int) int {
	for arr[i] != i {
		i = arr[i]
	}
	return i
}
func combineC(arr []int,i,j int)  {
	m,n:=findF(arr,i),findF(arr,j)
	if m!=n{
		arr[n]=m
		arr[j]=m
	}
}
```
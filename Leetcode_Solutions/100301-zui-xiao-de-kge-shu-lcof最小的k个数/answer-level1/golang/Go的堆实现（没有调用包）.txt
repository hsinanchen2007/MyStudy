Go的最大堆实现

```golang
func getLeastNumbers(arr []int, k int) []int {
	if k!=0&&k!=len(arr){
		buildMaxHeap(arr[0:k])
		for i:=k;i<len(arr);i++{
			if arr[i]<arr[0]{
				arr[0]=arr[i]
				adjustHeap(arr,0,k)
			}
		}
	}
	return arr[0:k]
}

func buildMaxHeap(arr []int)  {
	for i:=len(arr)/2-1; i>=0; i-- {
		adjustHeap(arr,i,len(arr))
	}
}
func adjustHeap(arr []int,i int,length int)  {
	for k:=2*i+1; k<length; k=2*k+1 {
		if k+1<length&&arr[k]<arr[k+1] {
			k=k+1
		}
		if arr[k]>arr[i] {
			arr[k],arr[i]=arr[i],arr[k]
			i=k
		}else {
			break
		}
	}
}
```
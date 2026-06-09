```
func findKthLargest(nums []int, k int) int {
return _findKthSmallest(nums,0,len(nums)-1,len(nums)-k)
}

func _findKthSmallest(arr []int,l ,r ,k int)int{
if l>= r{
return arr[l]
}
p := _partition(arr,l,r)
if k > p {
return _findKthSmallest(arr,p+1,r,k)
}else if k == p{
return arr[p]
}else{
return _findKthSmallest(arr,l,p-1,k)
}
}

func _partition(arr []int,l, r int)int{
v := arr[l]
j := l
i := j+1
for i =j+1;i<=r;i++{
if arr[i]<v{
arr[j+1],arr[i] = arr[i],arr[j+1]
j++}
}
arr[l],arr[j]= arr[j],arr[l]
return j
}

```

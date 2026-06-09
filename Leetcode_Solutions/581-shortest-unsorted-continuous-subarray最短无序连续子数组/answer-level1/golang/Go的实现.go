### 代码

```golang
func findUnsortedSubarray(nums []int) int {
    tmp := make([]int,len(nums))
	var index []int
	copy(tmp,nums)  //数组拷贝
	sort.Ints(tmp)
	for i:=0;i<len(nums);i++{
		if nums[i]==tmp[i]{
			continue
		}else{
			index = append(index,i)
		}
	}
	if len(index)==0{
		return 0
	}else{
		return index[len(index)-1]-index[0]+1
	}
}
```
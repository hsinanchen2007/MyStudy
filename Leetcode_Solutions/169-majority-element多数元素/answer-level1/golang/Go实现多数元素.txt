

```golang
func majorityElement(nums []int) int {
   left,right:= 0,len(nums)-1
   mid := left+(right-left)/2
   p := partition(nums,left,right)
   for p != mid{
       if p>mid{
           right = p-1
           p = partition(nums,left,right)
       }else{
           left = p+1
           p = partition(nums,left,right)
       }
   }
   result := nums[mid]
   return result
}

func partition(arr []int,left,right int)int{
	p1,p2 := left-1,right
	for left <p2{
		if arr[left]<arr[right]{
			arr[p1+1],arr[left] = arr[left],arr[p1+1]
			p1++
			left++
		}else if arr[left]>arr[right]{
			arr[p2-1],arr[left] = arr[left],arr[p2-1]
			p2--
		}else{
			left++
		}
	}
	arr[right],arr[p2] = arr[p2],arr[right]
	return p1+1
}

```
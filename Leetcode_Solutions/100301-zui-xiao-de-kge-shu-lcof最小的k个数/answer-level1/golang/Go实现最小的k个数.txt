**两种实现方法，partition函数与最大堆实现**

```golang
func getLeastNumbers(arr []int, k int) []int {
    if arr == nil || k<=0 || len(arr)<k{
        return []int{}
    }
    left,right := 0,len(arr)-1
    p:= partition(arr,left,right)
    for p != k-1{
        if p>k-1{
            right = p-1
            p = partition(arr,left,right)
        }else{
            left = p+1
            p = partition(arr,left,right)
        }
    }
    res := []int{}
    for i := 0;i<=p;i++{
        res = append(res,arr[i])
    }
    return res
}

func partition(arr []int,left,right int)int{
	p1 := left-1   //小于区域右边界
	p2 := right  //大于区域左边界
	for left<p2 {  //left表示当前数的位置   arr[right]划分值
		if arr[left]<arr[right]{   //当前数<划分值
			arr[p1+1],arr[left] = arr[left],arr[p1+1]
			p1++
			left++
		}else if arr[left]>arr[right]{   //当前数>划分值
			arr[left],arr[p2-1] = arr[p2-1],arr[left]
			p2--
		}else {   //当前数=划分值
			left++
		}
	}
	arr[right],arr[p2] = arr[p2],arr[right]
	return p1+1
}
```

```
func getLeastNumbers(arr []int, k int) []int {
    if arr == nil || k<=0 || len(arr)<k{
        return []int{}
    }
    res := []int{}
   for i := 0;i<k;i++{
       heapInsert(arr,i)
   }
   heapSize := k
   for i := k;i<len(arr);i++{
       if arr[i]<=arr[0]{
           arr[0],arr[i] = arr[i],arr[0]
           heapify(arr,0,heapSize)
       }
   }
   for i := 0;i<k;i++{
       res = append(res,arr[i])
   }
   return res
}

func heapInsert(arr []int, index int) {
	for arr[index] > arr[(index-1)/2] {
		arr[index], arr[(index-1)/2] = arr[(index-1)/2], arr[index]
		index = (index - 1) / 2
	}
}

func heapify(arr []int, index, heapSize int) {
	left := 2*index + 1
	for left < heapSize {
		largest := 0
		if left+1 < heapSize && arr[left] < arr[left+1] {
			largest = left + 1
		} else {
			largest = left
		}
		if arr[index] > arr[largest] {
			largest = index
		} else {
			largest = largest
		}
		if largest == index {
			break
		}
		arr[largest], arr[index] = arr[index], arr[largest]
		index = largest
		left = 2*index + 1
	}
}
```

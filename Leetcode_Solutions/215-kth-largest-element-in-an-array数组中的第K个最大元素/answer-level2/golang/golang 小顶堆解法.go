取出前k个元素构建小顶堆，当有新的元素比最小的元素大的时候，置换掉顶部元素，重新构建小顶堆
```
func findKthLargest(nums []int, k int) int {
    if len(nums) < 1 {
        return 0
    }

    if len(nums) == 1 {
        return nums[0]
    }

    arr := nums[:k]
    for i := (k - 2)/2; i>=0; i-- {
        heapify(arr, i, k)
    }

    for i:=k;i<len(nums);i++ {
        if arr[0] < nums[i] {
            arr[0] = nums[i]
            heapify(arr, 0, k)
        } 
    }

    return arr[0]
}

//除顶点外的堆结构正常
func heapify (a []int, k int, l int) {
    if k >= l {
        return
    }
    i := 2*k + 1 
    j := 2*k + 2
    min := k
    if i < l && a[i] < a[min] {
        min = i
    }

    if j < l && a[j] < a[min] {
        min = j
    }

    if min != k {
        swap(a, min, k)
        heapify(a, min, l)
    }  
}



func swap (a []int, i int, j int) {
    a[i], a[j] = a[j], a[i]
}

```

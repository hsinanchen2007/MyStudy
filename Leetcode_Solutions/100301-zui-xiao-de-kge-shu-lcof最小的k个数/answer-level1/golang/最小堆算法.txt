最小堆算法，空间时间秒杀，取前k个最小堆，迭代即可停止。

```go
func heapify(root int, length int, arr []int) {
    for root < length {
        min, left, right := root, 2*root+1, 2*root+2
        if left < length && arr[left] < arr[min] {
            min = left
        }
        if right < length && arr[right] < arr[min] {
            min = right
        }
        if min != root {
            arr[min], arr[root] = arr[root], arr[min]
            root = min
        }else{
            break
        }
    }
}

func getLeastNumbers(arr []int, k int) []int {
    for i := len(arr) / 2; i >= 0; i-- {
        heapify(i, len(arr), arr)
    }
    for i := len(arr) - 1; i >= len(arr)-k; i-- {
        arr[0], arr[i] = arr[i], arr[0]
        heapify(0, i, arr)
    }
    return arr[len(arr)-k:]
}
```

快速排序（暴力解法）
```golang
func quickSort(l int, r int, arr []int) {
    if l >= r {
        return
    }
    lo, hi, pivot := l, r, arr[r]
    for lo < hi {
        for lo < hi && arr[lo] <= pivot {
            lo++
        }
        arr[hi] = arr[lo]
        for lo < hi && arr[hi] >= pivot {
            hi--
        }
        arr[lo] = arr[hi]
    }
    arr[hi] = pivot
    quickSort(l, hi - 1, arr)
    quickSort(hi + 1, r, arr)
}

func getLeastNumbers(arr []int, k int) []int {
    quickSort(0, len(arr) - 1, arr)
    return arr[:k]
}
```


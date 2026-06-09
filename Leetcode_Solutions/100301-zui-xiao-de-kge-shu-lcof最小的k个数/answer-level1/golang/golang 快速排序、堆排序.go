
### 快速排序

```golang
func getLeastNumbers(arr []int, k int) []int {
    // 快速排序
    quickSort(arr)
    return arr[:k]
}

func quickSort(arr []int) {
    if len(arr) < 2 {
        return
    }
    mid, i := arr[0], 1
    head, tail := 0, len(arr) - 1
    for head < tail {
        if arr[i] > mid {
            arr[i], arr[tail] = arr[tail], arr[i]
            tail--
        }else {
            arr[i], arr[head] = arr[head], arr[i]
            head++
            i++
        }
    }
    arr[head] = mid
    quickSort(arr[:head])
    quickSort(arr[head+1:])
}

```

### 堆排序
```
func getLeastNumbers(arr []int, k int) []int {
    
    // 堆排序
    heapSort(arr)
    return arr[len(arr)-k:]
}

func heapSort(arr []int) []int {
    // 构建二叉堆
    length := len(arr)
    index := (length - 1) / 2 // 最后一个非叶子节点的索引
    for i := index; i >= 0; i-- {
        heapfiy(i, length - 1, arr)
    }
    // 排序
    for i := length-1; i >= 0; i-- {
        if arr[0] < arr[i] {
            arr[0], arr[i] = arr[i], arr[0]
            heapfiy(0, i - 1, arr)
        }
    }
    return arr
}

func heapfiy(index, end int,arr []int) []int {
    for {
        child := 2 * index + 1
        if child > end {
            break
        }
        if child+1 < end && arr[child] > arr[child+1] {
            child++
        }
        if child < end && arr[index] > arr[child] {
            arr[index], arr[child] = arr[child], arr[index]
            index = child
        }else {
            break
        }
    }
    return arr
}
```
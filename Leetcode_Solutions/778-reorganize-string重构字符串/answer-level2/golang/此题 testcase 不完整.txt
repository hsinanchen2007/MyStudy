本来以为是 1046 的翻版，用如下方法解决

```go
func left(i int) int {
    return 2 * i + 1
}

func right(i int) int {
    return 2 * i + 2
}

func maxHeapify(A []byte, n, i int, counter map[byte]int) {
    l := left(i)
    r := right(i)
    largest := i
    
    if l < n && counter[A[l]] > counter[A[i]] {
        largest = l
    }
    
    if r < n && counter[A[r]] > counter[A[largest]] {
        largest = r
    }
    
    if largest != i {
        A[i], A[largest] = A[largest], A[i]
        maxHeapify(A, n, largest, counter)
    }
}

func buildMaxHeap(A []byte, n int, counter map[byte]int) {
    for i := n / 2 - 1; i >= 0; i -- {
        maxHeapify(A, n, i, counter)
    }
}

func reorganizeString(S string) string {
    counter := make(map[byte]int)
    
    for i := 0; i < len(S); i ++ {
        if v, ok := counter[S[i]]; !ok {
            counter[S[i]] = 1
        } else {
            counter[S[i]] = v + 1
        }
    }
    
    keys := []byte{}
    for k, _ := range counter {
        keys = append(keys, k)   
    }
    
    n := len(keys)
    
    buildMaxHeap(keys, n, counter)
    
    result := []byte{}
    
    for n > 1 {
        largest := keys[0]
        keys[n - 1], keys[0] = keys[0], keys[n - 1]
        n --
        buildMaxHeap(keys, n, counter)
        
        second := keys[0]
        keys[n - 1], keys[0] = keys[0], keys[n - 1]
        n --
        buildMaxHeap(keys, n, counter)
        
        for i := 0; i < counter[largest] && i < counter[second]; i ++ {
            result = append(result, largest, second)
        }
        
        if counter[largest] > counter[second] {
            r := counter[largest] - counter[second]
            delete(counter, second)
            delete(counter, largest)
            counter[largest] = r
            n ++
            keys[n - 1] = largest
            buildMaxHeap(keys, n, counter)
        } else {
            delete(counter, second)
            delete(counter, largest)
        }
    }
    
    if n == 0 {
        return string(result)   
    } else {
        if counter[keys[0]] > 1 {
            return ""
        } else {
            result = append(result, keys[0])
            return string(result)
        }
    }
}
```

这种解法可以 beat 100% 的提交，但是是有缺陷的，比如 “aabbcc” 就不会得到正确输出。

改用如下方法可以通过这个 case

```
func left(i int) int {
    return 2 * i + 1
}

func right(i int) int {
    return 2 * i + 2
}

func maxHeapify(A []byte, n, i int, counter map[byte]int) {
    l := left(i)
    r := right(i)
    largest := i
    
    if l < n && counter[A[l]] > counter[A[i]] {
        largest = l
    }
    
    if r < n && counter[A[r]] > counter[A[largest]] {
        largest = r
    }
    
    if largest != i {
        A[i], A[largest] = A[largest], A[i]
        maxHeapify(A, n, largest, counter)
    }
}

func buildMaxHeap(A []byte, n int, counter map[byte]int) {
    for i := n / 2 - 1; i >= 0; i -- {
        maxHeapify(A, n, i, counter)
    }
}

func reorganizeString(S string) string {
    counter := make(map[byte]int)
    
    for i := 0; i < len(S); i ++ {
        if v, ok := counter[S[i]]; !ok {
            counter[S[i]] = 1
        } else {
            counter[S[i]] = v + 1
        }
    }
    
    keys := []byte{}
    for k, _ := range counter {
        keys = append(keys, k)   
    }
    
    n := len(keys)
    
    buildMaxHeap(keys, n, counter)
    
    result := []byte{}
    
    for n > 1 {
        largest := keys[0]
        keys[n - 1], keys[0] = keys[0], keys[n - 1]
        n --
        buildMaxHeap(keys, n, counter)
        
        second := keys[0]
        keys[n - 1], keys[0] = keys[0], keys[n - 1]
        n --
        buildMaxHeap(keys, n, counter)
        
        result = append(result, largest, second)
        
        counter[largest] -= 1
        if counter[largest] == 0 {
            delete(counter, largest)
        } else {
            n ++
            keys[n - 1] = largest
            buildMaxHeap(keys, n, counter)
        }
        
        counter[second] -= 1
        if counter[second] == 0 {
            delete(counter, second)
        } else {
            n ++
            keys[n - 1] = second
            buildMaxHeap(keys, n, counter)
        }
        
        // fmt.Println(counter, n)
    }
    
    if n == 0 {
        return string(result)   
    } else {
        if counter[keys[0]] > 1 {
            return ""
        } else {
            result = append(result, keys[0])
            return string(result)
        }
    }
}
```

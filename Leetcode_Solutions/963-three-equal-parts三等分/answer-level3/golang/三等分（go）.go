go的解决方法：
```
func threeEqualParts(A []int) []int {
    
    var no = []int{-1, -1}
    
    size := len(A)
    
    indexs := make([]int, 0, size)
    for i, val := range A {
        if val == 1 {
            indexs = append(indexs,i)
        }
    }
    
    count := len(indexs)
    
    if count == 0 {
        return []int{0, 2}
    }
    
    if count%3 != 0 {
        return no
    }
    
    c1, c2 := count/3, count/3*2
    s0, s1, s2 := indexs[0], indexs[c1], indexs[c2]
    
    for s2 < size && A[s0] == A[s1] && A[s1] == A[s2] {
        s0++
        s1++
        s2++
    }
    
    if s2 == size {
        return []int{s0 - 1, s1}
    }
    
    return no
}
```

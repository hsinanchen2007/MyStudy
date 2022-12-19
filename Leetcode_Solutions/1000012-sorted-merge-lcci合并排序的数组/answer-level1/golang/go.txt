双指针
```
func merge(A []int, m int, B []int, n int)  {
    var x = m - 1  //A的指针
    var y = n - 1  //B的指针
    var c = m + n -1  //实际欲插入的位置
    for y >= 0 {
        if x >= 0 && A[x] > B[y]{
            A[c] = A[x]
            x--
        }else{
            A[c] = B[y]
            y--
        }
        c--
    }
}
```

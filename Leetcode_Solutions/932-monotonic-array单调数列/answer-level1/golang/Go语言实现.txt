两个数的大小分三种情况：等于，大于，小于
设这三种情况分别为：0，1，2
二进制表示分别为00000000，00000001，00000010
然后挨个比较相邻的两个数将他们的情况进行按位或
如果出现多位为1的情况则不单调
```
func isMonotonic(A []int) bool {
    lenA := len(A)
    types, res := 0, true
    for i := 0; i < lenA - 1 && types != 3; i++{
        if A[i] > A[i+1]{
            types |= 1
        }else if A[i] < A[i+1]{
            types |= 2
        }  
    }
    if types == 3{
        res = false
    }
    return res
}
```
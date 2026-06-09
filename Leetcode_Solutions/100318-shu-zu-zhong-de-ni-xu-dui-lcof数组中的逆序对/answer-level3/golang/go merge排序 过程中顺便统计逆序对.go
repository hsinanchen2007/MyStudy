### 解题思路
此处撰写解题思路
go merge排序 
过程中顺便统计逆序对
用的带flag版本， noflag的 没有统计逆序对
### 代码

```golang
const INT_MAX = int(^uint(0)>>1)
const INT_MIN = ^INT_MAX
var count = 0;

func reversePairs(nums []int) int {
    count = 0;
    MergeSort(nums, 0, len(nums)-1)
    return count
}

func MergeSort(A []int, p, r int){

    if p < r {
        q := (p + r)/2
        MergeSort(A, p, q)
        MergeSort(A, q+1, r)
        merge(A, p, q, r)

    }
}

func merge(A []int, p, q, r int){
    n1 := q-p+1
    n2 := r-q
    
    L := make([]int, n1+1)
    R := make([]int, n2+1)
    
    for i := 0 ; i < n1; i++ {
        L[i] = A[p+i]
    }
    for j := 0 ; j < n2; j++ {
        R[j] = A[q+j+1]
    }

    L[n1] = INT_MAX
    R[n2] = INT_MAX
    i, j := 0, 0
    for k := p; k <= r; k++ {
        if L[i] <= R[j] {  //左边小于等于右边的处理掉  如L [4, 5] R [6, 7] 
            A[k]= L[i]
            i++
        }else{
            //统计逆序对   L [5, 7，INT_MAX] R [4, 6，INT_MAX] i=0时 左边有2对和4组成逆对
            count += len(L)-i-1 
            A[k] = R[j]
            j++
        }
    }
}

func merge_noflag(A []int, p, q, r int){
    n1 := q-p+1
    n2 := r-q
    
    L := make([]int, n1)
    R := make([]int, n2)
    
    for i := 0 ; i < n1; i++ {
        L[i] = A[p+i]
    }
    for j := 0 ; j < n2; j++ {
        R[j] = A[q+j+1]
    }
    i, j, k := 0, 0, 0
    for k = p; k <= r; k++ {
        if i < n1 && j < n2{   //not the end of n1 and n2
                if L[i] < R[j] {
                    A[k]= L[i]
                    i++
                }else{
                    A[k] = R[j]
                    j++
                }
        }else{
            break
        }
    }
    if i < n1 {
        for i< n1{
            A[k] = L[i]
            k++ 
            i++
        }
    }else{
        for j< n2{
            A[k] = R[j]
            k++ 
            j++
        }
    }
}
```
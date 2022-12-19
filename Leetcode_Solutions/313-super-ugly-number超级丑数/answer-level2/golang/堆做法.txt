```go
import "container/heap"

type UglyNums []int

func (u *UglyNums) Push(x interface{}) {
    *u = append(*u, x.(int))
}

func (u *UglyNums) Pop() interface{} {
    n := len(*u)
    x := (*u)[n-1]

    (*u) = (*u)[0:n-1]
    return x
}

func (u UglyNums) Swap(i, j int) {
    u[i], u[j] = u[j], u[i]
}

func (u UglyNums) Less(i, j int) bool{
    return u[i] < u[j]
}

func (u UglyNums) Len() int {
    return len(u)
}

func nthSuperUglyNumber(n int, primes []int) int {
    if n == 0 || n == 1{
        return n
    }
    h := new(UglyNums)

    heap.Push(h, 1)
    n--

    for n > 0 {
        x := heap.Pop(h).(int)
        
        for h.Len() > 0 && x == (*h)[0] { //去除重复的数据
            heap.Pop(h)
        }

        for i := 0; i < len(primes); i++ {
            heap.Push(h, x * primes[i])
        }
        n --
    }
    return heap.Pop(h).(int)
}

```
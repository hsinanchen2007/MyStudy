# TODO 本文尚未完成

以`A=[2,3,1,4,0]`为例子

先说一下思路。

对于数组`A`，索引数组`I=[0,1,2,3,4]`,则当`K=0`时，差值数组`S=A-I=[2,2,-1,1,-4]`。

小于等于索引可表示为`A<=I`,即`S = A-I <= 0`

首先对于向右平移数组，并与索引相减的问题，改为向左移动索引。

索引数组为I,则
```txt
        A=[2,3,1,4,0]
K=0 :   I=[0,1,2,3,4], S=[2,2,-1,1,-4]
K=1 :   I=[1,2,3,4,0], S=[1,1,-2,0,0]
K=2 :   I=[2,3,4,0,1], S=[0,0,-3,4,-1]
K=3 :   I=[3,4,0,1,2], S=[-1,-1,0,3,-2]
K=4 :   I=[4,0,1,2,3], S=[-2,3,-1,2,-3]

```

可以看出对任意K,`I=[(0+K)%n,(k+1)%n,(k+2)%n,...,(k+i)%n,...]`,其中n为数组长度,i为第几项。

则`S=A-I=[A[0]-(0+K)%n,A[1]-(k+1)%n,A[2]-(k+2)%n,...,A[i]-(k+i)%n,...]`
对于其中的`(i+K)%n`,
 - 当i<n-K时,(i+K)%n=i+K;
 - 当i>=n-k时,(i+K)%n=i+K-n

若判断S<=0,
 - 当i<n-K时,`S[i]=A[i]-(K+i)%n=A[i]-(K+i)<=0`,则K>=A[i]-i,且k<n-i
 - 当i>=n-K时,`S[i]=A[i]-(K+i)%n=A[i]-(i+K-n)<=0`,则K>=A[i]-i+n,且k>=n-i
又由于0<=K<n

对于第i项,求出来一个区间K∈[0,Min(-1*s,i)+1) ∪ [i+1,Min(-1*s+n+1,n)],此时可以得分。

则定义一个结果数组R[n]存储K对应的得分列表,遍历i,R对应的有得分的K项加1。
算法的复杂度为O(n^2)

# O(n^2)
```go
func Min(x,y int) int{
    if y<x {
        return y
    }
    return x
}

func bestRotation(A []int) int {
    n:=len(A)
    R:=make([]int,n)
    var s,e1,e2 int
    for i:=0;i<n;i++{
        s=A[i]-i
        e1=Min(-1*s,i)+1
        e2=Min(-1*s+n+1,n)
        for k:=0;k<e1;k++ {
            R[k]++
        }
        for k:=i+1;k<e2;k++{
            R[k]++
        }
    }
    m:=R[0]
    mk:=0
    for k:=0;k<n;k++ {
        if R[k]>m{
            m=R[k]
            mk=k
        }
    }
    return mk
}
```

# O(n*log(n))
经过上一步的分析，将区间添加折返特性，是在求对于不同的i,区间[i+1,-1*S[i]+n+1]的最大重合点的问题。
```txt
        A=[2,3,1,4,0]
K=0 :   I=[0,1,2,3,4], S=[2,2,-1,1,-4]
K=1 :   I=[1,2,3,4,0], S=[1,1,-2,0,0]
K=2 :   I=[2,3,4,0,1], S=[0,0,-3,4,-1]
K=3 :   I=[3,4,0,1,2], S=[-1,-1,0,3,-2]
K=4 :   I=[4,0,1,2,3], S=[-2,3,-1,2,-3]

i=0, 区间[2,4]
i=1, 区间[2,3]
i=2, 区间[-2,2]
i=3, 区间[0,1]
i=4, 区间[-4,0] 

```

```go
import (
    "sort"
    "fmt"
)

func bestRotation(A []int) int {
    n:=len(A)
    E:=make([]int,n+1)
    E[n]=20001
    // R:=make([]int,n)
    var e int
    // var ei1,ei2 int 0,n-1
    l:=0
    for i:=0;i<n;i++{
        e=n-(A[i]-i) //n-s
        fmt.Println(e)
        if e>=n{
            E[i]=e-n
            l++
        }else{
            E[i]=e
        }
    }
    fmt.Println(E)
    sort.Ints(E)
    fmt.Println(l,E)
    // sort.Sort(E[ei2+1:])
    m:=0
    mi:=0
    j:=0
    for i:=0;i<n;i++ {
        fmt.Println("i",i,l)
        l++
        if m<l {
            m=l
            mi=i
        }
        for E[j]<=i {
            l--
            fmt.Println("d",l,E[j])
            j++
            
        }
        
}
    return mi
}
```
# O(n)
```go
func bestRotation(A []int) int {
    n:=len(A)
    change:=make([]int,n)
    for i:=0;i<n;i++{
        change[(n-(A[i]-i)+1)%n]--
    }    
    max:=0
    maxi:=0
    score:=0
    for i:=1;i<n;i++ {
        score+=change[i]+1
        if max<score {
            max=score
            maxi=i
        }
}
    return maxi
}
```

参考：
[1]: https://leetcode-cn.com/problems/smallest-rotation-with-highest-score/solution/onde-shi-jian-fu-za-du-suan-fa-yi-ji-jie-xi-by-wan/
[2]: https://blog.csdn.net/magicbean2/article/details/79775616

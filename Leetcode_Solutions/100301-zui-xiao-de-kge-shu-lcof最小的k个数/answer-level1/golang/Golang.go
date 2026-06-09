### 解题思路
![image.png](https://pic.leetcode-cn.com/60f3903caf7a6dc7f8dd9aff874a015dcc4b5480ce233b1abbea7a8a58f8ed58-image.png)
利用快速查找的切分函数。
### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
    if k==0{
        return []int{}
    }else if k==len(arr){
        return arr
    }
    mid,lo,hi:=partition(arr,0,len(arr)-1),0,len(arr)-1
    for mid!=k-1{
        if mid>k-1{
            hi=mid-1
            mid=partition(arr,lo,hi)
        }else{
            lo=mid+1
            mid=partition(arr,lo,hi)
        }
    }
    return arr[0:k]
}

func partition(a []int,lo,hi int)int{
    exch:=func(i,j int){
        t:=a[i]
        a[i]=a[j]
        a[j]=t
    }
    i,j,k:=lo,hi+1,a[lo]
    for{
        i++
        for a[i]<k{
            if i==hi{
                break
            }
            i++
        }
        j--
        for k<a[j]{
            if j==lo{
                break
            }
            j--
        }
        if i>=j{
            break
        }
        exch(i,j)
    }
    exch(lo,j)
    return j
}
```
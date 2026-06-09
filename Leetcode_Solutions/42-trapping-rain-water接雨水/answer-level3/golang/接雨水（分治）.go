### 代码

```golang
func trap(height []int) int {
    return getResult(height,0,len(height)-1)
}

func findMax(h []int,l,r int)int{
    var res int =l
    for i:=l;i<=r;i++{
        if h[i]>h[res]{
            res=i
        }
    }
    return res
}

func getResult(h []int,l,r int)int{
    if l+1>=r{
        return 0
    }
    mid:=findMax(h,l,r)
    var left,right,res int
    if mid>1+l{
        left=findMax(h,l,mid-1)
        tk:=getMin( h[mid],h[left])
        for i:=left+1;i<mid;i++{
            res+=tk-h[i]
        }
        res+=getResult(h,l,left)
    }
    if mid+1<r{
        right=findMax(h,mid+1,r)
        tk:=getMin(h[mid],h[right])
        for i:=mid+1;i<right;i++{
            res+=tk-h[i]
        }
        res+=getResult(h,right,r)
    }
    return res
}

func getMin(a,b int)int{
    if a>b{
        return b
    }
    return a
}
```
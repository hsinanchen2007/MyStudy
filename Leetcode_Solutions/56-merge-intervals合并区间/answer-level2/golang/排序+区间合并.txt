### 解题思路
以区间头，区间尾做为第一第二关键字排序
从前往后判断能否合并

### 代码

```golang
func merge(intervals [][]int) [][]int {
    Sort(intervals,0,len(intervals)-1)
    if len(intervals)<2{
        return intervals
    }
    var res [][]int
    res=append(res,[]int{intervals[0][0],intervals[0][1]})  
    for i:=1;i<len(intervals);i++{
        if res[len(res)-1][1]<intervals[i][0]{
            res=append(res,[]int{intervals[i][0],intervals[i][1]})
        }else if res[len(res)-1][1]<intervals[i][1]{
            res[len(res)-1][1]=intervals[i][1]
        }
    }
    return res
}
func Sort(a [][]int,l,r int){
    if l>=r {
        return
    }
    ml,mr:=l+1,r
    for ml<mr{
        for ;ml<mr&&(a[ml][0]<a[l][0]||a[ml][0]==a[l][0]&&a[ml][1]<=a[l][1]);ml++{}
        for ;ml<mr&&(a[mr][0]>a[l][0]||a[mr][0]==a[l][0]&&a[mr][1]>=a[l][1]);mr--{}
        a[ml][0],a[mr][0]=a[mr][0],a[ml][0]
        a[ml][1],a[mr][1]=a[mr][1],a[ml][1]
    }
    if !(a[ml][0]<a[l][0]||a[ml][0]==a[l][0]&&a[ml][1]<a[l][1]){
        ml--
    }
    a[ml][0],a[l][0]=a[l][0],a[ml][0]
    a[ml][1],a[l][1]=a[l][1],a[ml][1]
    Sort(a,l,ml-1)
    Sort(a,ml+1,r)
}
```
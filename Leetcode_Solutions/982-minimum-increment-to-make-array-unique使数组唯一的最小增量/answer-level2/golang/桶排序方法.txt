### 解题思路
因为给了明确的取值范围，所以可以使用桶排序方法A中的数字都放入桶中。为了减少循环空位置浪费的时间，可以加入min，max设置循环起始时间和结束时间。
循环桶的时候，如果发现一个位置大于1，就往后面一个位置排(arr[i]-1)，操作计数也对应增加(arr[i]-1)
因为max的数可能会有多个还要往后排，所以得有一个判断条件：前一个位置已经为零，当前位置已经大于最大值。

### 代码

```golang
func minIncrementForUnique(A []int) int {

    arr := make([]int,80000)
    var max,cnt int
    min := 80000
    for _,v := range A {
        if v>max {
            max = v
        }
        if v<min{
            min = v
        }
        arr[v]++
    }
    for i:= min;i<80000;i++ {
        if i > max+1 && arr[i-1]==0{
            break
        }        
        if arr[i] > 1 {
            diff := arr[i] - 1
            cnt += diff
            arr[i+1] += diff
        }
    }
    return cnt

}
```
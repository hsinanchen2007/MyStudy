### 解题思路
此处撰写解题思路

### 代码

```golang
func findNumberIn2DArray(matrix [][]int, target int) bool {
   var re bool
   for _,v := range matrix{
        re = two(v,target)
        if re{
            break
        }
    }
    return re
}

func two(a []int,m int)bool{
    left := 0
    right := len(a)-1
    for left <=  right{
        mid := (left+right)/2
        if m == a[mid]{
            return true
        }else if m > a[mid]{
            left = mid+1
        }else{
            right = mid-1
        }
    }
    return false
}
```
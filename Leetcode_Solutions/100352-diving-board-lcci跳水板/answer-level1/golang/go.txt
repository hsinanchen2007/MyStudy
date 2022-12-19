### 解题思路
此处撰写解题思路

### 代码

```golang
func divingBoard(shorter int, longer int, k int) []int {
    if k == 0 {
        return []int{}
    }
    
    if shorter == longer {
        return  []int{k}
    }
    
    var res []int
    
    for i := 0; i <= k;i++ {
        a := 0 
        a = shorter * i + (k-i) * longer
        res = append(res,a)
    }
    
    sort.Ints(res)
    
    return res
}
```
```
func getRow(rowIndex int) []int {
    if rowIndex == 0 {
        return []int{1}
    }
    if rowIndex == 1{
        return []int{1,1}
    }
    temp := getRow(rowIndex-1)
    lenTemp := len(temp)
    res := make([]int,lenTemp+1)
    res[0] = 1
    res[lenTemp]=1
    for i := 0; i < lenTemp-1;i++{
        res[i+1] = temp[i]+temp[i+1]
    }
    return res
}
```

![image.png](https://pic.leetcode-cn.com/76dbaf5a5d97121617704c199491aa38025fa30a16c336a61d4ffacf47020752-image.png)
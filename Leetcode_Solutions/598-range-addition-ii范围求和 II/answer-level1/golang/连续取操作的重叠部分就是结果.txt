```
func maxCount(m int, n int, ops [][]int) int {
    lenOps :=  len(ops)
    maxA := m
    maxB := n
    for i := 0; i < lenOps; i++{
        if ops[i][0] < maxA{
            maxA = ops[i][0]
        }
        if ops[i][1]<maxB{
            maxB = ops[i][1]
        }    
    }
    return maxA * maxB
    
}
```

![image.png](https://pic.leetcode-cn.com/ebd68e9c692980888969a78889883d0a3c05a0cc10c1ecacd64879d102e0634c-image.png)
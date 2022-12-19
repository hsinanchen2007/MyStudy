差值排序
```
func twoCitySchedCost(costs [][]int) int {
    sum, lenCosts := 0, len(costs)
    for i := 0; i < lenCosts-1; i++{
        min := i      
        for j := i; j< lenCosts;j++{
            if costs[j][0]-costs[j][1] < costs[min][0]-costs[min][1]{
                min = j
            }     
        }
        temp := costs[i]
        costs[i] = costs[min]
        costs[min] = temp
    }
    for i:= 0; i < lenCosts;i++{
        if i < lenCosts/2{
            sum += costs[i][0]
        }else{
            sum += costs[i][1]
        }
    }
    return sum
}
```

![image.png](https://pic.leetcode-cn.com/aec959401e72fee0741119f7e6d133719cff49ef132a4c8a801817e5975986ca-image.png)
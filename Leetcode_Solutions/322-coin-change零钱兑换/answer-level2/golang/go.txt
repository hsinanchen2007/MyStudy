```
//dp
func coinChange(coins []int, amount int) int {
    dpDict := map[int]int{}
    for _,v := range coins{
        dpDict[v] = 1
    }
    dpDict[0] = 0
    for i:=1;i<=amount;i++{
        //dict里有 就不必计算
        if _,ok :=dpDict[i];ok{
            continue
        }
        //获取F(n-c)
        supportMin := -1
        for _,c := range coins{
            if v,ok := dpDict[i-c];ok{
                if supportMin == -1 || supportMin > v{
                    supportMin = v
                }
            }
        }
        if supportMin != -1{
            dpDict[i] = supportMin + 1
        }
    }
    if v,ok:= dpDict[amount];ok{
        return v
    }
    return -1
}
```

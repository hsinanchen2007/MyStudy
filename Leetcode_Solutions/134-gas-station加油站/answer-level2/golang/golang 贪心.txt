### 代码

```golang
func canCompleteCircuit(gas []int, cost []int) int {
    var length = len(gas)
    var surplus int
    var minSurplus = math.MaxInt32
    var minIndex = 0
    for i:=0;i<length;i++{
        surplus += gas[i] - cost[i]
        if surplus<minSurplus{
            minSurplus = surplus
            minIndex = i
        }
    }
    if surplus<0{
        return -1
    }
    return (minIndex+1)%length
}



```
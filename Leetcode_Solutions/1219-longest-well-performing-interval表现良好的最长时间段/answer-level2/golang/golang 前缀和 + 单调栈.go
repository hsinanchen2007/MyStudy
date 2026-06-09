### 解题思路
单调栈用于找比某个元素小（大）元素的位置

### 代码

```golang
func longestWPI(hours []int) int {
    ans := 0
    //prefixSum
    n := len(hours)
    prefixSum := make([]int,n+1)//0..n

    for i:=0;i<n;i++{
        if hours[i] >8{
            hours[i]  = 1
        }else{
            hours[i] = -1
        }
    }

    for i:=1;i<n+1;i++{
        prefixSum[i] += prefixSum[i-1] + hours[i-1]
    }

    //monoStack
    monoStack := make([]int,0,len(prefixSum))
    monoStack = append(monoStack,0)
    for i,ele := range prefixSum{
        if i == 0 {continue}
        if ele < prefixSum[monoStack[len(monoStack)-1]]{
            monoStack = append(monoStack,i)
        }
    }

    for i:= len(prefixSum) - 1 ;i>=0;i--{
        if len(monoStack) == 0 {break}
        for {
            if len(monoStack) == 0 {break}
            if prefixSum[i] - prefixSum[monoStack[len(monoStack)-1]] <= 0{break}
            ans = Max(ans,i - monoStack[len(monoStack)-1])
            monoStack = monoStack[0:len(monoStack)-1]           
        }
    }

    return ans
    


}

func Max (a,b int) int{
    if a >=b{
        return a
    }
    return b
}
```
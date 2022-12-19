### 解题思路
![image.png](https://pic.leetcode-cn.com/41d6c7f23c83e1ea5b42928fff32c6be32174e54ccad8645ecebad2779b4b5d7-image.png)


### 代码

```golang
func canCompleteCircuit(gas []int, cost []int) int {
    
    gasSum := 0
    costSum := 0

    start := 0
    temp := 0
    for i := range gas {

        temp += gas[i] - cost[i]
        for temp < 0 {
            temp -= (gas[start] - cost[start])
            start ++
        }

        gasSum += gas[i]
        costSum += cost[i]
    }

    if gasSum < costSum {
        return -1
    }

    if start > len(gas) - 1 {
        return 0
    }

    return start
}
```
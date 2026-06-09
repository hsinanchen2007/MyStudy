### 解题思路
此处撰写解题思路

### 代码

```golang
import (
    "sort"
)

func coinChange(coins []int, amount int) int {
    if amount == 0 {
        return 0
    }
    if len(coins) == 0 {
        return -1
    }
    if len(coins) == 1 {
        if amount % coins[0] == 0 {
            return amount / coins[0]
        }
        return -1
    }
    var min int = -1
    sort.Sort(sortInt(coins))
    return getMin(coins, amount, 0, len(coins)-1, min)
}

func getMin(coins []int, amount, k, i ,min int) int {
    if amount == 0 {
        return k
    }
    if i == -1 {
        if min == -1 {
            return -1
        }
        return min
    }
    for j:= amount / coins[i]; j >=0; j-- {
        if min != -1 && j+k >= min {
            break
        }
        min = getMin(coins, amount - j*coins[i], j+k, i-1, min)
    }
    return min
}

type sortInt []int
func (s sortInt) Len() int {return len(s)}
func (s sortInt) Swap(i, j int) {s[i], s[j] = s[j], s[i]}
func (s sortInt) Less(i, j int) bool {return s[i] < s[j]} 
```
### 解题思路
1.核心思想：将数组进行排序，先尽量用更多最大的，然后依次将最大硬币的数量减少再试，然后再从第二大的开始试。
2.最先找到的不一定是最优解，比如[1, 7, 10]，14，那么最先找到的就是10+1+1+1+1，但是7+7才是最优的，因此需要把每种情况都找完。
3.如果数组当前的最大值比剩下的amount还要大，那么没必要将数组右边的数纳入组合，直接缩小数组范围，直到范围中所有的数都<=amount，这样可以减少递归次数。

参考：[ikaruga的题解](https://leetcode-cn.com/problems/coin-change/solution/322-by-ikaruga/)

### 代码

```golang
func coinChange(coins []int, amount int) int {
    sort.Ints(coins)
    var best int = 0x7FFFFFFF
    Change(coins, amount, 0, &best)

    if best<0x7FFFFFFF{
        return best
    }
    return -1
}

func Change(sortedCoins []int, amount int, bigCount int, best *int) {
    if amount == 0{
        if bigCount<*best{
            *best = bigCount
        }
        return
    }
    lenCoins := len(sortedCoins)
    if lenCoins==0 || sortedCoins[0]>amount {
        return
    }
    // 为了减少递归的层数
    for lenCoins>0 && sortedCoins[lenCoins-1]>amount{
        lenCoins--;
    }
    if lenCoins==0{
        return
    }
    count := amount/sortedCoins[lenCoins-1]
    for ; count>=0 && count+bigCount<*best; count--{
        Change(sortedCoins[:lenCoins-1], amount-count*sortedCoins[lenCoins-1], bigCount+count, best)
    }
}
```
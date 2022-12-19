### 解题思路
d[i][j]表示前i个币种组合j的总数量，则d[i][j]=d[i-1][j]+d[i][j-coins[i-1]]，白话就是，=包含第i个币种+不包含第i个币种

### 代码

```golang
func change(amount int, coins []int) int {
    d:=make([][]int,len(coins)+1)
    for i:=0;i<=len(coins);i++{
        d[i]=make([]int,amount+1)
    }
    for i:=0;i<=len(coins);i++{
        d[i][0]=1
    }

    for i:=1;i<=len(coins);i++{
        for j:=1;j<amount+1;j++{
            tmp:=0
            if j-coins[i-1] >=0{
                tmp = d[i][j-coins[i-1]]
            }
            d[i][j]=d[i-1][j]+tmp
        }
    }
    return d[len(coins)][amount]

}
```
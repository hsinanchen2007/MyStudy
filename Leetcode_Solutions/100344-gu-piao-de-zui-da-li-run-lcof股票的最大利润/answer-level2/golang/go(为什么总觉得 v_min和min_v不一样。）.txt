### 解题思路
 [7,1,5,3,6,4]

因为只可以交易一次，所以找到最小值（1），然后和后面的数字做差，记录结果，并比较大小。

### 代码

```golang
func maxProfit(prices []int) int {
    if len(prices) == 0 {
        return 0
    }
    max := prices[0]
    min := prices[0]

    res := 0 

    for _, value := range prices {
        if max < value {
            max = value
            if max - min > res {
                res = max - min
            }
        }
        if value < min {
            min = value
            max = value
        }
    }
    return res
}

```
### 解题思路
对不起我认为这个题目并不简单。。。。写完我自己都晕乎了，我是逐步判断波谷和波峰，看了取巧的答案实在惭愧

### 代码

```golang
func maxProfit(prices []int) int {
    pree := -1
    maxIndex := len(prices) -1
    if maxIndex < 1 {
        return 0
    }
    totalMake := 0
    low := -1
    for i, num  := range prices {
        if i == maxIndex { // 收尾
            if low != -1 {
                totalMake += num - low
            }
        }else{
            if num == prices[i+1] {
                continue
            }
            if (num < pree|| i == 0 || pree == -1)&& prices[i+1] > num {   // 判断买入
                low = num
            }else {    // 判断卖出
                if num > pree && num > prices[i+1] {
                if low != -1 {
                    totalMake += num - low
                    low = -1
                }
            }
            }
            
            }
        pree = num
       
    }
    return totalMake
}
```
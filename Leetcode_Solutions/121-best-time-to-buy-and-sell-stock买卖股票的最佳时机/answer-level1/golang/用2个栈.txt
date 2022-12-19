### 解题思路
递减栈stack1（从左往右）和递增栈stack2（从右往左）
最后2个数组同位相减的最大值就是最大收益
### 代码

```golang
func maxProfit(prices []int) int {
    stack1:=make([]int,len(prices))
    stack2:=make([]int,len(prices))
    for i:=0;i<len(prices);i++ {
        if i==0 || prices[i]<stack1[i-1]{
            stack1[i] = prices[i]
        } else {
            stack1[i] = stack1[i-1]
        }
    }
    for i:=len(prices)-1;i>=0;i-- {
        if i==len(prices)-1 || prices[i]>stack1[i+1]{
            stack2[i] = prices[i]
        } else {
            stack2[i] = stack2[i+1]
        }
    }
    max:=0
    for i:=0;i<len(prices);i++ {
        if stack2[i]-stack1[i]>max {
            max=stack2[i]-stack1[i]
        }
    }
    return max
}
```
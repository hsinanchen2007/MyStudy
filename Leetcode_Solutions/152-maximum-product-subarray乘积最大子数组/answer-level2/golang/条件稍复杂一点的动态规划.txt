和爬梯子那题不一样的是，本题的dp状态转移方程要复杂一点。通常我们都会在没次推演的时候，记录下当前最大值。但是本题由于有负数的情况，需要考虑两个负数相乘得正数，很有可能比当前最大值更大。因此一直保留并传递最小值也是必要的。

如果用二维数组dp[][]可以得到每个元素为根节点的答案。但是空间复杂度为O(N). 但题目只要全局最大值，也就是要根节点为nums[0]处的答案，因此可以仅仅声明两个变量big,small就可以了，空间降到O(1).

```go
func maxProduct(nums []int) int {
    n := len(nums)
    if n == 1 {
        return nums[0]
    }
    big := nums[n-1]
    small := big
    ans := big
    for i:=n-2;i>=0;i-- { // 需要记住动态规划都要从底向上递推
        big,small = getMaxAndMin(big,small,nums[i])
        if ans < big {
            ans = big
        }
    }
    return ans

}

func getMaxAndMin(big,small,new int) (max,min int){
    ns := []int{big*new,small*new} //需要考虑两个负数相乘得正数，所以递推过程需要保留最小值
    max = new
    min = new
    for _,v := range ns {
        if v>max {
            max = v
        }else if v < min{
            min = v
        }
    }
    return max,min
}
```

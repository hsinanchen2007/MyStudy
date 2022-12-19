用f(i)表示以数组中第i位结尾的可能存在的所有连续子序列的最大值。
则可知:

如果f(i-1) < 0 说明以第i-1位截止的连续子序列是个负数，如果在加上i位的数据，会导致值变小
因此  f(i) = sums[i]

如果 f(i-1) > 0 说明以第i-1位截止的连续子序列是个正数，对于以第i位结尾的子序列来说，肯定是加上前面这段，能让可能的序列和变大。
因此 f(i) = f(i-1) + sums[i]

通过这种逻辑我们可以在一次遍历中得到以每一位结尾的连续子序列的最大值，并从中选出最大的那个即可。

将此逻辑转化为代码则如下所示：

```
func maxSubArray(nums []int) int {
    result := 0
    signal := make([]int,len(nums))
    if len(nums) > 0 {
        signal[0] = nums[0]
        result = nums[0]
    }
    for i:=1;i<len(nums);i++ {
        if signal[i-1] < 0 {
            signal[i] = nums[i]
        } else {
            signal[i] = signal[i-1] + nums[i]
        }
        if signal[i] > result {
            result = signal[i]
        }
    }
    return result
}
```

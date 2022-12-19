### 解题思路
1. 如果都是正数，遍历一次记录前三大的三个值，求乘积即可。
2. 如果存在负数，绝对值最大的前三个值里，必须有两个负数或者三个都是正数。

综上：遍历一遍数组，记录最小的前2个和最大的前三个数。在min1*min2*max1 和max1*max2*max3中选最大值。
但是这样需要记录5个值(min1,min2,max1,max2,max3)，可以用一个数组存放，每次插入排序。

### 代码

```golang
func maximumProduct(nums []int) int {
    //思路:
    //如果都是正数，遍历一次记录前三大的三个值，求乘积即可。
    //如果有负数，找到绝对值最大的前三个数，并做判断，如果有两个负数，或者三个都是正数，ok。如果有一个负数，则把该负数替换成第三大的正数。求乘积。
    // 综上：遍历一遍数组，记录最小的前三个和最大的前三个数。在min1*min2*max1 和max1*max2*max3中选最大值。
    sort.Ints(nums)
    n := len(nums)
    max1 := nums[0]*nums[1] * nums[n-1]
    max2 := nums[n-3]*nums[n-2] * nums[n-1]
    if max1> max2{
        return max1
    }
    return max2
}
```
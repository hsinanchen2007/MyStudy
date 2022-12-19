初始化：
1. 设每次所选的起跳位置为start，
2. 能到的最大距离end为i+nums[start]，
3. 我们为了能用最小的次数跳到终点，每次都想跳到最大的位置为max。
4. 跳的次数为count

思路：
我们为了保证count最小，所以每次跳都要这一跳能跳的最远位置，解题思路应为贪心算法。

我们从前向后遍历，每完成一次跳跃后更新count与end的值，下一次的i即从上一跳的最远处$end_{i-1}(=start_i)$开始计算，遍历位置$start_i$到$end_i$得到能跳的最远处max，然后当遍历到$end_i$时，更新下一跳的起点$start_{i+1}$为max

```go
func jump(nums []int) int {
    if nums == nil || len(nums) == 0{
        return -1
    }
    
    n := len(nums)
    count,max,end := 0,0,0
    for i:=0;i<n-1;i++{
        
        // 记录每一个位置i所能跳到的最大位置max
        if i+nums[i]>max{
            max = i+nums[i]
        }
        // end是上一个所选的起跳位置能跳的最远处，当到达end时，更新下一跳的最大位置
        if i == end{
            end = max
            count++
        }
    }
    return count
}
```
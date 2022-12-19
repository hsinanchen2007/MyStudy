

思路历程：

1. 最先想到的就是分情况讨论，列举相交的情况，分别判断。然后发现很麻烦，一般这种人肉筛选都会被面试官笔bs。

2. 然后就想到了反向讨论，出现不想交的情况，也只有点重合和边重合这两种大类。简单很多。但是还是人肉，不通过

3. 之后想到一个，固定一个rect-A，然后另一个rect中只要有一个点落在A里就行了。发现case举少了。和第一个重合。不通过

4. 中心点的方法。判断两个rect的中心点连线长度。后来发现需要开方，又是int，整体长度也在10^9。开销太大，肯定不是最优解。

5. 更深层次的看，本质上就是求公共解的问题。但是需要注意边界的情况。就是不能有[]，只能有()。没有闭区间。只有开区间。

代码：

```
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    xlMax := max(rec1[0],rec2[0])
    xrMin := min(rec1[2],rec2[2])
    ylMax := max(rec1[1],rec2[1])
    yrMin := min(rec1[3],rec2[3])
    if xlMax < xrMin && ylMax < yrMin {
        return true
    }
    return false
}

func min(a,b int) int{
    if a < b{
        return a
    }
    return b
}

func max(a,b int) int {
    if a< b {
        return b
    }
    return a
}
```
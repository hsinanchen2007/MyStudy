根据两个区间的重叠情况来判断是否满足要求。所有区间问题，基本上都可以用这个解法。
首先列出两区间的所有位置情况：
1. 相离
![image.png](https://pic.leetcode-cn.com/48e0f38420b719b0704b3d96bc24755bee07ee2d19a14e88f6be091d01cd4e5f-image.png)
2. 相交
![image.png](https://pic.leetcode-cn.com/fc6ebf08c44ca9ca859332572efa6a4655502245ce690174844b4fb4d7fdb0a5-image.png)
3. 包含
![image.png](https://pic.leetcode-cn.com/cdd9e9a31c6b072676335add581b5f9879f12e1e36d8ccee11a6b7f4f1dd26c2-image.png)
4. 包含
![image.png](https://pic.leetcode-cn.com/bc0976d56d948ec77664c406aca8f335dff33019de8e4df788e2c7467ad58db3-image.png)
5. 相交
![image.png](https://pic.leetcode-cn.com/dc70cdd55e6601bb6cecb5ffc5153ae617997c30805ea28313dd1fdeab8e449d-image.png)
6. 相离
![image.png](https://pic.leetcode-cn.com/79487d4f71ab5f4e62cad70c5c8ab9fcac4e9da72c4d3badb95d68b41709d01e-image.png)

（1，6）：相离，没有相交的区间
（2，3）：A 的尾永远大于 B 的尾。所以相交的区间为 `[min(A[0], B[0]), B[1]]`
（4，5）：B 的尾永远大于 A 的尾。所以相交的区间为 `[min(A[0], B[0]), A[1]]`


本题需要找到满足预计时间的最早时间间隔。首先将 `slots1` 和 `slots2` 按照开始时间大小排序。
从头开始比较两个区间。判断相交区间大小是否大于 `duration`，如果大于直接返回。如果不满足条件，将结束时间早的区间向前进1


完整代码：
```go
func minAvailableDuration(slots1 [][]int, slots2 [][]int, duration int) []int {
    // 排序
    sort.Slice(slots1, func(i, j int) bool {
        return slots1[i][0] < slots1[j][0]
    })
    sort.Slice(slots2, func(i, j int) bool {
        return slots2[i][0] < slots2[j][0]
    })
    for i, j := 0, 0; i < len(slots1) && j < len(slots2); {
        if slots1[i][0] >= slots2[j][1] { // 对应上面 （1）
            j++
        } else if slots1[i][1] >= slots2[j][1] && slots1[i][0] < slots2[j][1] { // 对应上面（2，3）
            end := slots2[j][1]
            start := max(slots1[i][0], slots2[j][0])
            if end - start >= duration { // 判断区间是否大于要求
                return []int{start, start + duration}
            }
            j++
        } else if slots1[i][1] < slots2[j][1] && slots1[i][1] > slots2[j][0] { // 对应上面（4，5）
            end := slots1[i][1]
            start := max(slots1[i][0], slots2[j][0])
            if end - start >= duration {
                return []int{start, start + duration}
            }
            i++
        } else { // 对应上面（6）
            i++
        }
    }
    return []int{}
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```

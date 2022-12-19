### 解题思路
如果分割后的数组中，最大数的下标与nums[i]所代表的值不相等，那么排序后，就无法形成从小到大的连贯的数组了，所以只有找到最大的数与下标当等时，用来计数的count才能加1，如果没有找到，那么子数组继续向后寻找，找到后重新查找新的子数组

### 代码

```golang
func maxChunksToSorted(arr []int) int {
    if len(arr) < 2 {
        return len(arr)
    }

    //目的是找出分割的数组中，最大值等于index的数，有的话就加1
    //count用来计算个数，cur用来表示最大的数
    count := 0
    cur := arr[0]
    for i, v := range arr {
        cur = max(cur, v)
        //如果最大的数与对应的下标相等，那么说明排序后是从小到大，能够链接起来的
        if cur == i {
            count++
        }
    }
    return count
}
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```
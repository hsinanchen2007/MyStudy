### 解题思路
此处撰写解题思路

### 代码

```golang
// 快排实现
func findKthLargest(nums []int, k int) int {
    len := len(nums)
    // 对数组进行排序
    sort(nums, 0, len - 1)
    return nums[k-1]
}

// 快排的递归模版
func sort(arr []int, start int, end int) {
    // 递归退出条件
    if start >= end {
        return
    }
    // 去查找中值,本层递归需要处理的都在这处理，下层递归与本层无关
    i := cut(arr, start, end)
    // 分段递归，进入下一层递归
    sort(arr, start, i - 1)
    sort(arr, i + 1, end)
}

// 返回中值
func cut(arr []int, start int, end int) int {
    // 比较值
    pivot := arr[end]
    // 双指针, i用来保存比pivot小的数据,j为探索指针一直向前
    i, j := start, start
    for ; i<end && j<end; {
        if arr[j] > pivot {
            // 当前数据小于比较值，交换数据
            arr[j], arr[i] = arr[i], arr[j]
            i++
        }
        j++
    }
    // 交换中间数据
    arr[i], arr[end] = arr[end], arr[i]
    // 返回中间索引
    return i
}




```
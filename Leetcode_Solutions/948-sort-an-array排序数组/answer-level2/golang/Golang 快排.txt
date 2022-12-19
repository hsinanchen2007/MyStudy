### 解题思路
重新温习了一遍  各类排序算法  
快排 
1. 先设定一个基准值，以此作为分界线.
2. 将数组分割成两部分 一部分比基准值小，另一部分比基准值大。
3. 递归此操作  
### 代码

```golang
func sortArray(nums []int) []int {
    return quickSort(nums, 0, len(nums) - 1)
}


func quickSort(arr []int, left, right int) []int {
    if left < right {
        partitionIndex := partition(arr, left, right)
        quickSort(arr, left, partitionIndex - 1)
        quickSort(arr, partitionIndex + 1, right)
    }
    return arr
}

func partition(arr []int, left, right int) int {
    pivot := left
    index := pivot + 1
    for i := index; i <= right; i++ {
        if arr[i] < arr[pivot] {
            arr[i], arr[index] = arr[index], arr[i]
            index++
        }
    }
    arr[pivot], arr[index - 1] = arr[index - 1], arr[pivot]
    return index - 1
}
```
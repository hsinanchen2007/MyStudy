所有思想在代码注释中呈现，欢迎交流
```
func findKthLargest(nums []int, k int) int {
    // 堆排序
    // 构建长度为k的小顶堆，遍历元素，如果元素大于最小值，则替换堆顶值，并调整堆，最后输出堆顶即是第k大值
    // 1. 构建堆 容量为k 0~k-1
    for i := k / 2 - 1; i >= 0; i-- {
        adjustHeap(&nums, i, k)
    }

    // 2 遍历剩余元素 调整堆
    for i := k; i < len(nums); i++ {
        if nums[0] < nums[i] {
            nums[0], nums[i] = nums[i], nums[0]
            adjustHeap(&nums, 0, k)
        }
    }
    return nums[0]
}

// 小顶堆
func adjustHeap(nums *[]int, i, length int) {
    tmp := (*nums)[i]
    for k := 2*i+1; k < length; k = 2*k+1 { // 从左子节点开始调整
        if k + 1 < length && (*nums)[k+1] < (*nums)[k] {
            k++
        }
        if (*nums)[k] < tmp {
            (*nums)[i] = (*nums)[k]
            i = k
        } else {
            break
        }
        (*nums)[i] = tmp
    }
}

// func findKthLargest(nums []int, k int) int {
//     // 快排实现 查找倒数第N-k个元素
//     target := 0
//     fastQuick(&nums, 0, len(nums) - 1, k, &target)
//     return target
// }

// func fastQuick (nums *[]int, left, right int, k int, target *int) {
//     if left > right {
//         return 
//     }

//     index := getIndex(nums, left, right)
//     if index == right - k + 1 {
//         *target = (*nums)[index]
//         return 
//     }

//     if index < right - k + 1 {
//         // 在右边
//         fastQuick(nums, index + 1, right, k, target)
//     } else {
//         fastQuick(nums, left, index - 1, k - (right - index) - 1, target)
//     }
// }

// func getIndex(nums *[]int, left, right int) int {
//     tmp := (*nums)[left]
//     for left < right {
//         for left < right && (*nums)[right] >= tmp {
//             right--
//         }
//         (*nums)[left] = (*nums)[right]
//         for left < right && (*nums)[left] <= tmp {
//             left++
//         }
//         (*nums)[right] = (*nums)[left]
//     }
//     (*nums)[left] = tmp
//     return left
// }
```

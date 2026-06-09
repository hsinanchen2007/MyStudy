### 解题思路
详见代码注释
```
执行用时 :
8 ms
, 在所有 golang 提交中击败了
86.19%
的用户
内存消耗 :
2.9 MB
, 在所有 golang 提交中击败了
100.00%
的用户
```

### 代码

```golang
func fourSum(nums []int, target int) [][]int {
    // 对数组进行排序
    Sort(nums)
    n := len(nums)
    // 定义返回的数组
    result := make([][]int, 0)
    // 从数组左侧开始进行遍历,固定左侧第一个值
    for i := 0; i < n - 3; i++ {
        // 如果最小值都大于0，则整个数组都没有符合要求的组合
        if nums[i] + nums[i+1] + nums[i+2] + nums[3] > target {
            break
        }
        // 确保nums[i]改变了
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        // 固定第二个值，第二个值都取值范围为外循环左侧+1到外循环右侧-1
        // 这里其实可以理解为对三数求和了,步骤与三数求和一致了
        for b := i + 1; b < (n - 2); b++ {
            // 去重
            if b > i + 1 && nums[b] == nums[b-1] {
                continue
            }
            //左右两侧都固定好了，用左指针和右指针夹逼
            L := b + 1
            R := n - 1
            for L < R {
                sum := nums[i] + nums[b] + nums[L] + nums[R]
                if sum == target {
                    // 保存四个数
                    item := make([]int, 4)
                    item[0] = nums[i]
                    item[1] = nums[b]
                    item[2] = nums[L]
                    item[3] = nums[R]
                    result = append(result, item)
                    // 左指针去重
                    for L < R && nums[L] == nums[L+1] {
                        L++
                    }
                    // 右指针去重
                    for L < R && nums[R] == nums[R-1]{
                        R--
                    }
                    
                    R--
                    L++
                    
                } else if sum > target {
                    // 和比目标值大，因为左侧如果继续右移，值只会比当前值大，所以需要右指针变小即向左移动
                    R--
                } else {
                    L++
                }
            }
        }
    }
    return result
}

func Sort(nums []int) {
    sort(nums, 0, len(nums) - 1)
}

func sort(nums []int, start int, end int) {
    if start >= end {
        return
    }
    i := cut(nums, start, end)
    sort(nums, start, i - 1)
    sort(nums, i + 1, end)
}

func cut(arr []int, start int, end int) int {
    pivot := arr[end]
    p := start
    q := start
    for ; q < end; q++ {
        if arr[q] < pivot {
            arr[p], arr[q] = arr[q], arr[p]
            p++
        }
    }
    arr[p], arr[end] = arr[end], arr[p]
    return p
}
```
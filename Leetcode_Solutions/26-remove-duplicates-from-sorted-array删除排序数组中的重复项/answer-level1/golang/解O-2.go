### 解题思路
需要两个变量记录前一个的元素值和现在应该将发现的不同元素放在数组的哪个位置

+ 执行用时 : 8 ms, 在所有 golang 提交中击败了97.11%的用户
+ 内存消耗 : 4.6 MB, 在所有 golang 提交中击败了100.00%的用户
### 代码

```golang
func removeDuplicates(nums []int) int {
    if len(nums) <= 1 {
        return len(nums)
    }

    var index int = 1
    var pre int = nums[0]
    for i, v := range nums {
        if i == 0 || v == pre {
            continue
        }
        if v != pre {
            nums[index] = v
            index++
            pre = v
        }
    }
    return index
}

/**
    是排序数组，所以相同元素一定相邻

*/
```
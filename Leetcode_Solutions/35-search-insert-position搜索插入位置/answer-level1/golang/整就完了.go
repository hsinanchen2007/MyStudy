### 解题思路
此处撰写解题思路
1、二分查找
2、查不到再遍历找位置，应该可以优化，找时间研究一下
### 代码

```golang
func searchInsert(nums []int, target int) int {

    if len(nums) == 0 || target < nums[0]{
        return 0
    }

    if target > nums[len(nums)-1] {
        return len(nums)
    }

    length := len(nums)
    low := 0
    high := length -1
    for low <= high {
        mid := low + ((high - low) >> 2)
        if target < nums[mid]{
            high = mid - 1
        }else if target > nums[mid]{
            low = mid + 1
        }else {
            return mid
        }
    }


    var res int
    for i := 0; i < len(nums)-1;i++ {
        if nums[i] < target && nums[i+1] >= target {
            res = i + 1
            break
        }
        }
        return res
    }
```
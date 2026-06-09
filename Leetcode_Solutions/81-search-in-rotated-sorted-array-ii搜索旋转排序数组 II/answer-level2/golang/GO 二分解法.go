![image.png](https://pic.leetcode-cn.com/011a3fe31534bb5773b46b94885c8137dd1bc1239be6cad0cda4e465a8048f5a-image.png)


### 代码

```golang
func search(nums []int, target int) bool {
    l, r := 0, len(nums)

    if r == 0 {
        return false
    }

    mid := int((l + r) / 2)

    if nums[mid] == target {
        return true
    }

    if mid == 0 {
        return false
    }

    // if left is sorted
    if nums[0] < nums[mid - 1] {
        // if target in left
        if nums[0] <= target && target <= nums[mid - 1] {
            return search(nums[0:mid], target)
        }
    }

    // if right is sorted
    if nums[mid] < nums[r - 1] {
        // if target in right
        if nums[mid] <= target && target <= nums[r - 1] {
            return search(nums[mid:], target)
        }
    }

    return search(nums[0:mid], target) || search(nums[mid:], target)
}
```
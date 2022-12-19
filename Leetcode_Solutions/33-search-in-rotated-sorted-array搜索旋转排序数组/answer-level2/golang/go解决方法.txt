### 解题思路
1. 二分查找旋转点
2. 确定二分查找区间
3. 二分查找目标值

### 代码

```golang
func search(nums []int, target int) int {

    if len(nums) == 0{
        return -1
    } else if len(nums) == 1{
        if nums[0] == target {
            return 0
        }
        return -1
    }

	p := rotationIndex(nums)

	low := 0
	high := len(nums) - 1

	if p != -1 {
		if nums[p] == target {
			return p
		}
		if nums[len(nums)-1] >= target {
			low = p + 1
			high = len(nums)-1
		} else if nums[0] <= target {
			low = 0
			high = p
		} else {
			return -1
		}
	}

	return targetIndex(nums,low, high, target)
}

func rotationIndex(nums []int) int {

	low := 0
	high := len(nums) - 1
	p := -1

	for low < high {
		mid := low + (high-low)>>1

		if mid != len(nums) -1 && nums[mid] > nums[mid+1] {
			p = mid
			break
		} else if mid != 0 && nums[mid - 1] > nums[mid] {
			p = mid - 1
			break
		} else if nums[mid] > nums[low] {
			low = mid + 1
		} else if nums[mid] < nums[high] {
			high = mid - 1
		}
	}

	return p
}

func targetIndex(nums []int, low, high, target int) int {

	for low <= high {
		mid := low + (high-low)>>1

		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			high = mid - 1
		} else if nums[mid] < target {
			low = mid + 1
		}
	}
	return -1
}

```
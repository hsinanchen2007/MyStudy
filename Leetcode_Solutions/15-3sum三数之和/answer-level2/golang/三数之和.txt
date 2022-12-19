### 解题思路


### 代码

```golang
import(
    "sort"
)
func threeSum(nums []int) [][]int {
    rs := [][]int{}
    length := len(nums)
    if length < 3 {
        return rs
    }
    sort.Ints(nums)
    
    for i := 0; i < len(nums) - 2;i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        left  := i + 1
        right := len(nums) - 1
        for left < right {
            sum := nums[i] + nums[left] + nums[right]
            if sum > 0 {
                right--
            } else if sum < 0 {
                left++
            } else {
                rs = append(rs, []int{nums[i], nums[left], nums[right]})
                for left < right && nums[left] == nums[left + 1] {
                    left++
                }
                for left < right && nums[right] == nums[right - 1] {
                    right--
                }
                left++
                right--
            }
        }
    }
    
    return rs
}

func heapSort(arr []int) {
    if len(arr) < 2 {
        return
    }

    parent := len(arr)/2 - 1
    for i := parent; i >= 0;i-- {
        left  := 2 * i + 1
        right := 2 * 2 + 2
        if left < len(arr) && arr[i] > arr[left] {
            arr[i], arr[left] = arr[left], arr[i]
        }
        if right < len(arr) && arr[i] > arr[right] {
            arr[i], arr[right] = arr[right], arr[i]
        }
    }
}

func quickSort(arr []int) {
    if len(arr) < 2 {
        return
    }
    quick(arr, 0, len(arr) - 1)
}

func quick(arr []int, low, high int) {
    if low < high {
        index := getIndex(arr, low, high)
        quick(arr, 0, index - 1)
        quick(arr, index + 1, high)
    }
}

func getIndex(arr []int, low, high int) int {
    temp := arr[low]
    for low < high {
        for low < high && temp <= arr[high] {
            high--
        }
        arr[low], arr[high] = arr[high], arr[low]
        for low < high && temp >= arr[low] {
            low++
        }
        arr[low], arr[high] = arr[high], arr[low]
    }
    return low
}
```
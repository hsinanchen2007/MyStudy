```
import "math"
func splitArray(nums []int, m int) int {
    //二分查找，数组划分只能为1-l份

    //low: 数组划分为l份时，子数组的最大值 = 数组中的最大值
    //high：数组划分为1份时，子数组的最大值 = 数组的和
    //mid: 数组划分为n份时，子数组的最大值
    //如果该最大值的划分块数比m 大， 则low 为mid + 1, 反之， high = mid
    low := 0
    high := 0
    for _, e := range nums {
        low = int(math.Max(float64(e), float64(low)))
        high += e
    }

    for (low < high) {
        mid := low + (high - low) / 2
        if spilt(nums, mid) > m {
            low = mid + 1  
        } else {
            high = mid 
        }
    }

    return low
}

func spilt(nums []int, largestSum int) int {
    pieces := 1
    tmpSum := 0

    for i := 0; i < len(nums); i++ {
        if (tmpSum + nums[i]) > largestSum {
            tmpSum = nums[i]
            pieces++
        } else {
            tmpSum += nums[i]
        }
    }
    return pieces
}
```

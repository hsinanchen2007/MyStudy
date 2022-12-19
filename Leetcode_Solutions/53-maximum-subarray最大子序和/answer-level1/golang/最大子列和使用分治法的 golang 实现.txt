我觉得有一个需要注意的问题是，在求跨越边界的子序列最大和的时候要注意初始的最大值不应该是 0，应该是起始位置的值，否则全是负数的时候，求出来的结果就不对了。

```golang
func maxSubArray(nums []int) int {
    return divideAndConquer(nums, 0, len(nums)-1)
}

func divideAndConquer(nums []int, left, right int) int {
    if left == right {
        return nums[left]
    }

    mid := left + (right - left) / 2

    leftSum := divideAndConquer(nums, left, mid)
    rightSum := divideAndConquer(nums, mid+1, right)

    leftCrossBorderInitSum := nums[mid] 
    maxLeftCrossBorderSum := leftCrossBorderInitSum

    for i:= mid-1; i >= left; i-- {
        leftCrossBorderInitSum += nums[i]
        if leftCrossBorderInitSum > maxLeftCrossBorderSum {
            maxLeftCrossBorderSum = leftCrossBorderInitSum
        }
    }

    rightCrossBorderInitSum := nums[mid+1]
    maxRightCrossBorderSum := rightCrossBorderInitSum
    for j := mid+2; j<= right; j++ {
        rightCrossBorderInitSum += nums[j]
        if rightCrossBorderInitSum > maxRightCrossBorderSum {
            maxRightCrossBorderSum = rightCrossBorderInitSum
        }
    }
    return max(leftSum, rightSum, maxLeftCrossBorderSum + maxRightCrossBorderSum)
}

func max(leftSum, rightSum, crossBorderSum int) int {
    if leftSum >= rightSum && leftSum >= crossBorderSum {
        return leftSum
    }
    if rightSum >= leftSum && rightSum >= crossBorderSum {
        return rightSum
    }
    return crossBorderSum
}
```
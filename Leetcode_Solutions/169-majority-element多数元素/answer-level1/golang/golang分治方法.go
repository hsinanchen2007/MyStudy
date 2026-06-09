### 解题思路
//分治方法

### 代码

```golang

func majorityElement(nums []int) int {
    return merger(nums, 0, len(nums) - 1)
}

func merger(nums []int, i int, j int) int {
    if i == j {
        return nums[i]
    }
    mid := (i + j) >> 1
    left  := merger(nums, i, mid)
    right := merger(nums, mid+1, j)
    if left == right {
        return left
    }
    leftCnt := 0
    rightCnt := 0
    for ;i < mid ; i++ {
        if left == nums[i] {
            leftCnt++
        }
    }
    for ; mid < j; mid++ {
        if right == nums[mid] {
            rightCnt++
        } 
    }
    if leftCnt > rightCnt {
        return left
    }
    return right
}


```
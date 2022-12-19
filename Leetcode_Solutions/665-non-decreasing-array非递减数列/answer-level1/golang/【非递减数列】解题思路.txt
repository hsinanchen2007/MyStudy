### 解题思路
1.遍历nums，计算出当前idx与idx-1的value差值数组
2.遍历过程中，累加差值为负数的个数，记住差值为负数的下标
3.若个数为零，则返回true；若个数大于1，无法只更改一个数达到目的，则返回false
4.只剩下个数为1的情况，根据之前记住的下标判断，如果为第二个数(可更改第一个数达到目的)、最后一个数(可更改最后一个数达到目的)，则返回true
5.若以上情况都未进入，说明是数组中间有较小的数，判断该数对应的差值与左边/右边差值之和是否为正，只要存在为正的情况，就说明该数可以通过修改达到目的，返回true；否则返回false

### 代码

```golang
func checkPossibility(nums []int) bool {
    diffs := make([]int, len(nums))
    invalidNum, invalidIdx := 0, -1
    for i := 1; i < len(nums); i++ {
        diffs[i] = nums[i] - nums[i-1]
        if diffs[i] < 0 {
            invalidNum++
            invalidIdx = i
        }
    }
    if invalidNum > 1 {
        return false
    } else if invalidNum == 0 {
        return true
    } 

    if diffs[invalidIdx] < 0 {
        if invalidIdx == 1 || invalidIdx == len(nums)-1 {
            return true
        } else {
            return diffs[invalidIdx] + diffs[invalidIdx+1] >= 0 || diffs[invalidIdx] + diffs[invalidIdx-1] >= 0
        }
    }
    return true
}
```
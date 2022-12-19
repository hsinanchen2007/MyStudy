### 解题思路
比较容易想到的思路是利用双指针，从数组两边向中间逼近。
1. 因为是有序数组，数组中大于目标值右边都可以排除，这是最容易想的，可以单独判断排除，也可以在第2步中排除，效果相同
2. 如果numbers[left] + numbers[right] > target, 说明右边的值过大，继续往前找
3. 左边思路与右边相同。

### 代码

```golang
func twoSum(numbers []int, target int) []int {
    size := len(numbers)
    if size < 2 {
        return []int{}
    }

    left, right := 0, size - 1
    for left < right {
        if numbers[left] + numbers[right] > target { // 从右往左逼近
            right--
        } else if numbers[left] + numbers[right] < target {  // 从左往右逼近
            left++
        } else {
            return []int{left + 1, right + 1}
        }
    }
    return []int{}
}
```
### 解题思路
有序数组首先想到了二分查找，记录一下这道题，提醒读者，对于有序数组还可以使用双指针法。使用两个指针left从左向右查找，right从右向左查找，没走一步，计算一下指针处的值，大于right左移，小于左指针右移，知道找到符合条件的值。

### 代码

```golang
func twoSum(numbers []int, target int) []int {
    left:=0
    right:=len(numbers)-1

    for left<right{
        sum:=numbers[left]+numbers[right]
        if sum==target{
            return []int{left+1,right+1}
        }else if sum>target{
            right--
        }else{
            left++
        }
    }

    return []int{}
}
```
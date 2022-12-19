### 解题思路

按照插入位置可分为两种情况：
1.插入位置在数组范围外
2.插入位置在数组范围内

上述第二种情况又可分为两种情况：
1.数组内存在数字等于待插入的数字
2.数组内不存在数字等于待插入的数字

### 代码

```golang
func searchInsert(nums []int, target int) int {
	var index int
    if target > nums[len(nums) - 1]{
        index = len(nums)
    }else{
        for i := 0; i < len(nums); i++ {
            if nums[i] == target {
                index = i
                break
                } else {
                    if nums[i] > target {
                        index = i
                        break
                    }
                }
            }
    }
    return index
}
```
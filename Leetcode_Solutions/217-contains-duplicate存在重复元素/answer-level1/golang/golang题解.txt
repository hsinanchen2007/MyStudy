先考虑到特殊情况，**nums数组元素为0和1，直接返回false**  
设置计数变量`count`，将第一次遍历数组得到的元素与第二次遍历数组得到的元素做判断，如果两数相等，就将`count`加1，在结束循环后对`count`做判断，`count`值不等于0返回`true`，否则返回`false`。  

这里尤其需要注意，第一次遍历数组的下标一定比第二次遍历出的数组元素下标大，举个例子：  
输入`[1,2,3,1]`，判断这个数组里有没有重复元素，第一次遍历`nums[0]`得到1，那么第二次遍历时肯定不能从`nums[0]`开始，必须从`nums[1]`开始往后累加，不然在同一个数组中，将下标相等的两个元素做比较，肯定相等，从而AC不通过。  

```go
func containsDuplicate(nums []int) bool {
    if len(nums) == 0 || len(nums) == 1 {
        //考虑nums特殊情况
        return false
    }

    count := 0
    for i:=0;i<len(nums);i++ {
        for j := i+1;j<len(nums);j++ {
            if nums[i] == nums[j] {
                count++
            }
        }    
    }

    if count != 0 {
        return true
    } else {
        return false
    }
}
```

[文章链接](https://octopuslian.github.io/2019/12/07/Leetcode-217-contains-duplicate/)
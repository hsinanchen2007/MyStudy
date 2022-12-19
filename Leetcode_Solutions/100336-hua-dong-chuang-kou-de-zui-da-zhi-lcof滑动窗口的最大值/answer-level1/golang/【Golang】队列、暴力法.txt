# 解法一：队列——解题思路
- 设置变量 max 用于记录窗口中的最大值的索引
- **窗口滑动后**
 	- 如果出去的值(的索引)是最大值(的索引)，那么新的窗口则需要**重新查找最大值并设置 max** 
 	 	- 这里使用双指针查找窗口中的最大值 / (最大值的索引)
 	- 如果出去的值不是最大值(的索引)，则判断新进来的值是否大于当前的最大值
 	 	- 不大于则最大值(的索引)可不变
        - 大于则将进来的值(的索引)作为最大值(的索引)

---

## 写法一：比较下标

**--执行用时：16 ms   --内存消耗：6.4 MB**

```go
func maxSlidingWindow(nums []int, k int) []int {
    if len(nums) == 0 || k <= 0 || k > len(nums){
        return nil
    }
    var maxNums []int
    //max用于记录窗口中的最大值的索引
    max := -1
    for i:=0;i<=len(nums)-k;i++{
        l := i
        r := i+k-1
        //如果出去的值是最大值(的索引)，那么新的窗口需要重新查找最大值并设置
        if max == -1 || max == l-1 {
            max = getMax(nums,l,r)
        }else{
        //如果出去的值不是最大值(的索引)，则判断新进来的值是否大于当前的最大值
            //不大于则最大值(的索引)不变
            //大于则将进来的值(的索引)作为最大值(的索引)
            if nums[r] > nums[max] {
                max = r
            }
        }
        maxNums = append(maxNums,nums[max])
    }
    return maxNums
}

//双指针查找最大值的索引
func getMax(nums []int,left,right int) int {
    for left<right{
        if nums[left]>nums[right]{
            right--
        }else{
            left++
        }
    }
    return left
}
```
## 写法二：比较值本身
--执行用时：20 ms --内存消耗：6.4 MB
```go
func maxSlidingWindow(nums []int, k int) []int {
    if len(nums) == 0 || k <= 0 || k > len(nums){
        return nil
    }
    var maxNums []int
    maxNow:=max(nums[0:k])
    maxNums=append(maxNums,maxNow)
    for i:=1;i<=len(nums)-k;i++{
        if nums[i-1]==maxNow{
            maxNow=max(nums[i:i+k])
            maxNums=append(maxNums,maxNow)
        }else{
            if nums[i+k-1]<=maxNow{
                maxNums=append(maxNums,maxNow)
            }else{
                maxNow=max(nums[i:i+k])
                maxNums=append(maxNums,maxNow)
            }
        }
    }
    return maxNums
}

func max(nums []int) int {
    left:=0
    right:=len(nums)-1
    for left<right{
        if nums[left]>nums[right]{
            right--
        }else{
            left++
        }
    }
    return nums[left]
}
```

---

# 解法二:暴力法

**--执行用时：44 ms   --内存消耗：6.4 MB**

```go
func maxSlidingWindow(nums []int, k int) []int {
    if len(nums) == 0 || k <= 0 || k > len(nums){
        return nil
    }
    var maxNums []int
    for i:=0;i<=len(nums)-k;i++{
        maxNums=append(maxNums,max(nums[i:i+k]))
    }
    return maxNums
}

func max(nums []int) int {
    left:=0
    right:=len(nums)-1
    for left<right{
        if nums[left]>nums[right]{
            right--
        }else{
            left++
        }
    }
    return nums[left]
}
```

---

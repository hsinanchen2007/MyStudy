### 解题思路
交换思想
### 注意点
内循环的长度
### 优化
由于每次比较都是从头到尾的比较，如果该次循环一直没交换过，说明排序已经完成。
```
func sortArray(nums []int) []int {
    // 冒泡排序
    // 两个两个比较大小，将较大值放到后面
    for i := 0; i < len(nums) - 1; i++ {
        flag := true
        for j := 0; j < len(nums) - 1 - i; j++ {
            if nums[j] > nums[j+1] {
                nums[j], nums[j+1] = nums[j+1], nums[j]
                flag = false
            }  
        }
        if flag {// 从头到尾都没有进行交换，说明已经排序完成
            break
        }
    }
    return nums
}
```
